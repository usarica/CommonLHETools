/** \class LHEHandler
 *
 *
 *  \author N. Amapane - Torino
 *  \author U. Sarica - UCSB/JHU
 *  \author H. Roskes - JHU
 *
 *
 */
#ifndef LHEHADNLER_H
#define LHEHANDLER_H

#include <DataFormats/Common/interface/Handle.h>
#include <SimDataFormats/GeneratorProducts/interface/LHERunInfoProduct.h>
#include <SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h>
#include <ZZMatrixElement/MELA/interface/Mela.h>
#include <MelaAnalytics/EventContainer/interface/MELAEvent.h>

#include <vector>
#include <cmath>


class LHEHandler{
public:
  enum KinematicsMode{
    noKinematics=0,
    doBasicKinematics=1,
    doHiggsKinematics=2
  };

  LHEHandler(int VVMode_, int VVDecayMode_, LHEHandler::KinematicsMode doKinematics_, int year_);
  LHEHandler(edm::Handle<LHEEventProduct>* lhe_evt_, int VVMode_, int VVDecayMode_, LHEHandler::KinematicsMode doKinematics_, int year_);
  virtual ~LHEHandler();
  
  void setHandle(edm::Handle<LHEEventProduct>* lhe_evt_);
  void extract();
  void clear();

  MELACandidate* getBestCandidate();
  float const& getLHEOriginalWeight() const; // Weight written in the <event> block, supposed to = genhepmcweight if no Pythia reweighting is done
  float const& getPowhegOriginalWeight() const; // Weight from POWHEG before JHUGen reweighting, taken from alternate weight 1001.  If there are no alternate weights this is the same as the LHEOriginalWeight
  float getLHEWeight(unsigned int whichWeight, float defaultValue=1) const; // = {Weights written in LHE weight variations} / getLHEOriginalWeight()
  float getLHEWeight_PDFVariationUpDn(int whichUpDn, float defaultValue=1) const; // = {Weights written in LHE weight variations} / getLHEOriginalWeight()
  float getLHEWeigh_AsMZUpDn(int whichUpDn, float defaultValue=1) const; // = {Weights written in LHE weight variations} / getLHEOriginalWeight()
  float const& getPDFScale() const;
  float reweightNNLOtoNLO() const;

  float getWeightRescale() const; // Nominal weight should be getLHEOriginalWeight() * getWeightRescale()

  // Misc. functions needed for ordering the PDF weights
  static bool compareAbsIsLess(float val1, float val2);
  static void suppressLargeWeights(std::vector<float>& wgt_array);
  static float findNearestOneSigma(float ref, int lowhigh, std::vector<float> const& wgt_array);
  static float safeDivide(float numerator, float denominator){ return (!(std::isfinite(numerator) && std::isfinite(denominator)) || denominator==0.f ? 0.f : numerator/denominator); }

protected:

  // VVMode and VVDecayMode: See comment lines within MELAEvent::constructVVCandidates
  const int VVMode;
  const int VVDecayMode;
  const LHEHandler::KinematicsMode doKinematics;
  const int year;

  edm::Handle<LHEEventProduct>* lhe_evt;
  std::vector<MELAParticle*> particleList;
  MELAEvent* genEvent;
  MELACandidate* genCand;

  float defaultNLOweight;
  float LHEOriginalWeight;
  float powhegOriginalWeight;
  std::vector<float> LHEWeight;
  std::vector<float> LHEWeight_PDFVariationUpDn;
  std::vector<float> LHEWeight_AsMZUpDn;
  std::vector<int> PDFid;
  float PDFScale;

  void readEvent();

  enum AlternateWeightsType {
    unknown,
    powheg,
    madgraph_0offset,
    madgraph_1000offset
  };

};


#endif
