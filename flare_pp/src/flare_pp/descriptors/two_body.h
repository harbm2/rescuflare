#ifndef TWO_BODY_H
#define TWO_BODY_H

#include "descriptor.h"
#include "structure.h"
#include <string>
#include <vector>

class TwoBody : public Descriptor {
public:
  double cutoff;
  int n_species;

  std::function<void(std::vector<double> &, double, double,
                     std::vector<double>)>
      cutoff_function;
  std::string cutoff_name;
  std::vector<double> cutoff_hyps;

  std::string descriptor_name = "TwoBody";

  TwoBody();
  TwoBody(double cutoff, int n_species, const std::string &cutoff_name,
          const std::vector<double> &cutoff_hyps);

  DescriptorValues compute_struc(Structure &structure);

  nlohmann::json return_json();
};

#endif
