#include <vector>
#include <iostream>
#include "vecops.h"
#include "MersenneTwister.h"

MTRand r_gen;

std::vector<int> randMoves(std::size_t size, unsigned max_amplitude) {
  std::vector<int> v(size); // uniform random in [-max,-1]U[1,max]
  unsigned m = max_amplitude-1;
  for(auto &x: v) {
    x = r_gen.randInt(m)+1;
    if (r_gen.randInt(1)) {
        x = -x;
    }
  }
  return v;
}

void periodize(std::vector<int> &sites, int lattice_size)
{
    for (auto &s: sites) {
        auto m = s/lattice_size;
        if (s<0) {
            m--;
        }
        s -= m*lattice_size;
    }
}

std::vector<unsigned> getActive(const std::vector<unsigned> &occupancy,
                                const std::vector<unsigned> &passive_states)
{
    auto is_passive = vops::isin(occupancy, passive_states);
    std::vector<unsigned> active_sites;
    for (unsigned i=0; i<is_passive.size(); i++) {
        if (!is_passive[i]) {
            active_sites.push_back(i);
        }
    }
    return active_sites;
}

void moveActive(std::vector<unsigned> &occupancy,
                const std::vector<unsigned> &active_sites,
                unsigned nb_active_particles,
                unsigned max_amplitude)
{
    auto moves = randMoves(nb_active_particles, max_amplitude);

    std::vector<int> new_sites (nb_active_particles);
    unsigned k = 0;
    for (auto a: active_sites) {
        for (unsigned j=0; j<occupancy[a]; j++) {
            new_sites[k] = a + moves[k];
            k++;
        }
    }
    periodize(new_sites, occupancy.size());

    for (auto i: active_sites) {
        occupancy[i] = 0;
    }
    for (auto i: new_sites) {
        occupancy[i]++;
    }
}

unsigned timeStep(std::vector<unsigned> &occupancy,
                  const std::vector<unsigned> &passive_states,
                  unsigned max_amplitude)
{
    auto active_sites = getActive(occupancy, passive_states);
    unsigned nb_active_particles = 0;
    for (auto a: active_sites) {
        nb_active_particles += occupancy[a];
    }
    moveActive(occupancy, active_sites, nb_active_particles, max_amplitude);
    return nb_active_particles;
}

int main(int argc, char** argv) {

    double density = std::stod(argv[1]);
    unsigned L = std::stoul(argv[2]);
    unsigned max_amplitude = std::stoul(argv[3]);

    auto N = (unsigned)(density*L);
    std::vector<unsigned> occupancy (L);
    for (unsigned int i=0; i<N; i++) {
        occupancy[r_gen.randInt(L-1)]++;
    }
    std::vector<unsigned> passive_states = {0, 1, 5, 6, 7, 8, 9, 10};
    unsigned active;
    unsigned iter=0;
    unsigned print_period = 1e4;
    do {
        active = timeStep(occupancy, passive_states, max_amplitude);
        iter++;
        if (iter%print_period == 0) {
            std::cout << iter << " " << active << std::endl;
        }
    } while(active && iter < 1e5);
    if (!active) {
        std::cout << "solved in " << iter << std::endl;
    } else {
        std::cout << "reached max iter (" << iter << ")" << std::endl;
    }
}
