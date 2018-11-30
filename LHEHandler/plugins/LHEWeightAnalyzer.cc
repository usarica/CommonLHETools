#include <memory>
#include <cmath>
#include <algorithm>

#include <FWCore/Framework/interface/EDAnalyzer.h>
#include "FWCore/Framework/interface/Event.h"
#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <FWCore/ServiceRegistry/interface/Service.h>
#include <CommonTools/UtilAlgos/interface/TFileService.h>

#include <CommonLHETools/LHEHandler/interface/LHEHandler.h>

#include "TTree.h"


float LHEweight_Scaled_NNPDF30_LO; float LHEweight_Original_NNPDF30_LO; float LHEweight_MemberZero_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO; float LHEweight_PDFVariation_Up_NNPDF30_LO; float LHEweight_PDFVariation_Dn_NNPDF30_LO; float LHEweight_AsMZ_Up_NNPDF30_LO; float LHEweight_AsMZ_Dn_NNPDF30_LO;
float LHEweight_Scaled_NNPDF30_NLO; float LHEweight_Original_NNPDF30_NLO; float LHEweight_MemberZero_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO; float LHEweight_PDFVariation_Up_NNPDF30_NLO; float LHEweight_PDFVariation_Dn_NNPDF30_NLO; float LHEweight_AsMZ_Up_NNPDF30_NLO; float LHEweight_AsMZ_Dn_NNPDF30_NLO;
float LHEweight_Scaled_NNPDF30_NNLO; float LHEweight_Original_NNPDF30_NNLO; float LHEweight_MemberZero_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO; float LHEweight_PDFVariation_Up_NNPDF30_NNLO; float LHEweight_PDFVariation_Dn_NNPDF30_NNLO; float LHEweight_AsMZ_Up_NNPDF30_NNLO; float LHEweight_AsMZ_Dn_NNPDF30_NNLO;

float LHEweight_Scaled_NNPDF31_LO; float LHEweight_Original_NNPDF31_LO; float LHEweight_MemberZero_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO; float LHEweight_PDFVariation_Up_NNPDF31_LO; float LHEweight_PDFVariation_Dn_NNPDF31_LO; float LHEweight_AsMZ_Up_NNPDF31_LO; float LHEweight_AsMZ_Dn_NNPDF31_LO;
float LHEweight_Scaled_NNPDF31_NLO; float LHEweight_Original_NNPDF31_NLO; float LHEweight_MemberZero_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO; float LHEweight_PDFVariation_Up_NNPDF31_NLO; float LHEweight_PDFVariation_Dn_NNPDF31_NLO; float LHEweight_AsMZ_Up_NNPDF31_NLO; float LHEweight_AsMZ_Dn_NNPDF31_NLO;
float LHEweight_Scaled_NNPDF31_NNLO; float LHEweight_Original_NNPDF31_NNLO; float LHEweight_MemberZero_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO; float LHEweight_PDFVariation_Up_NNPDF31_NNLO; float LHEweight_PDFVariation_Dn_NNPDF31_NNLO; float LHEweight_AsMZ_Up_NNPDF31_NNLO; float LHEweight_AsMZ_Dn_NNPDF31_NNLO;

using namespace std;
using namespace edm;
//
// class declaration
//
class LHEWeightAnalyzer : public edm::EDAnalyzer {
public:

  explicit LHEWeightAnalyzer(const edm::ParameterSet&);
  ~LHEWeightAnalyzer();

protected:
  virtual void beginJob();
  virtual void endJob();
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&){}
  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&){}

  virtual void analyze(const edm::Event&, const edm::EventSetup&);

  virtual void FillLHEWeights(LHEHandler const* lheHandler, float& LHEweight_Scaled, float& LHEweight_Original, float& LHEweight_MemberZero, float& LHEweight_QCDscale_muR1_muF1, float& LHEweight_QCDscale_muR1_muF2, float& LHEweight_QCDscale_muR1_muF0p5, float& LHEweight_QCDscale_muR2_muF1, float& LHEweight_QCDscale_muR2_muF2, float& LHEweight_QCDscale_muR2_muF0p5, float& LHEweight_QCDscale_muR0p5_muF1, float& LHEweight_QCDscale_muR0p5_muF2, float& LHEweight_QCDscale_muR0p5_muF0p5, float& LHEweight_PDFVariation_Up, float& LHEweight_PDFVariation_Dn, float& LHEweight_AsMZ_Up, float& LHEweight_AsMZ_Dn);

  // ----------member data ---------------------------
  int year;
  TString theTreeName;
  TTree* tree;
  LHEHandler* lheHandler_NNPDF30_NNLO;
  LHEHandler* lheHandler_NNPDF30_NLO;
  LHEHandler* lheHandler_NNPDF30_LO;
  LHEHandler* lheHandler_NNPDF31_NNLO;
  LHEHandler* lheHandler_NNPDF31_NLO;
  LHEHandler* lheHandler_NNPDF31_LO;

  edm::EDGetTokenT<LHERunInfoProduct> lheRunInfoToken;

};



LHEWeightAnalyzer::LHEWeightAnalyzer(const edm::ParameterSet& pset) :
  year(pset.getParameter<int>("year")),
  theTreeName("weightsTree"),
  tree(nullptr)
{
  consumesMany<LHEEventProduct>();
  lheRunInfoToken = consumes<LHERunInfoProduct, edm::InRun>(edm::InputTag("externalLHEProducer"));
  lheHandler_NNPDF30_NNLO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF30, LHEHandler::tryNNLO
  );
  lheHandler_NNPDF30_NLO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF30, LHEHandler::tryNLO
  );
  lheHandler_NNPDF30_LO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF30, LHEHandler::tryLO
  );
  lheHandler_NNPDF31_NNLO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF31, LHEHandler::tryNNLO
  );
  lheHandler_NNPDF31_NLO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF31, LHEHandler::tryNLO
  );
  lheHandler_NNPDF31_LO = new LHEHandler(
    -1, -1,
    (false ? LHEHandler::doHiggsKinematics : LHEHandler::noKinematics),
    year, LHEHandler::tryNNPDF31, LHEHandler::tryLO
  );
}

LHEWeightAnalyzer::~LHEWeightAnalyzer(){
  delete lheHandler_NNPDF30_NNLO;
  delete lheHandler_NNPDF30_NLO;
  delete lheHandler_NNPDF30_LO;
  delete lheHandler_NNPDF31_NNLO;
  delete lheHandler_NNPDF31_NLO;
  delete lheHandler_NNPDF31_LO;
}


void LHEWeightAnalyzer::analyze(const edm::Event& event, const edm::EventSetup& eSetup){
  // LHE information
  edm::Handle<LHEEventProduct> lhe_evt;
  vector<edm::Handle<LHEEventProduct> > lhe_handles;
  event.getManyByType(lhe_handles);
  if (!lhe_handles.empty()){
    lhe_evt = lhe_handles.front();

    lheHandler_NNPDF30_NNLO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_NNLO->extract();
    FillLHEWeights(lheHandler_NNPDF30_NNLO, LHEweight_Scaled_NNPDF30_NNLO, LHEweight_Original_NNPDF30_NNLO, LHEweight_MemberZero_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO, LHEweight_PDFVariation_Up_NNPDF30_NNLO, LHEweight_PDFVariation_Dn_NNPDF30_NNLO, LHEweight_AsMZ_Up_NNPDF30_NNLO, LHEweight_AsMZ_Dn_NNPDF30_NNLO);
    lheHandler_NNPDF30_NNLO->clear();
    lheHandler_NNPDF30_NLO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_NLO->extract();
    FillLHEWeights(lheHandler_NNPDF30_NLO, LHEweight_Scaled_NNPDF30_NLO, LHEweight_Original_NNPDF30_NLO, LHEweight_MemberZero_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO, LHEweight_PDFVariation_Up_NNPDF30_NLO, LHEweight_PDFVariation_Dn_NNPDF30_NLO, LHEweight_AsMZ_Up_NNPDF30_NLO, LHEweight_AsMZ_Dn_NNPDF30_NLO);
    lheHandler_NNPDF30_NLO->clear();
    lheHandler_NNPDF30_LO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_LO->extract();
    FillLHEWeights(lheHandler_NNPDF30_LO, LHEweight_Scaled_NNPDF30_LO, LHEweight_Original_NNPDF30_LO, LHEweight_MemberZero_NNPDF30_LO, LHEweight_QCDscale_muR1_muF1_NNPDF30_LO, LHEweight_QCDscale_muR1_muF2_NNPDF30_LO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO, LHEweight_QCDscale_muR2_muF1_NNPDF30_LO, LHEweight_QCDscale_muR2_muF2_NNPDF30_LO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO, LHEweight_PDFVariation_Up_NNPDF30_LO, LHEweight_PDFVariation_Dn_NNPDF30_LO, LHEweight_AsMZ_Up_NNPDF30_LO, LHEweight_AsMZ_Dn_NNPDF30_LO);
    lheHandler_NNPDF30_LO->clear();
    lheHandler_NNPDF31_NNLO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_NNLO->extract();
    FillLHEWeights(lheHandler_NNPDF31_NNLO, LHEweight_Scaled_NNPDF31_NNLO, LHEweight_Original_NNPDF31_NNLO, LHEweight_MemberZero_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO, LHEweight_PDFVariation_Up_NNPDF31_NNLO, LHEweight_PDFVariation_Dn_NNPDF31_NNLO, LHEweight_AsMZ_Up_NNPDF31_NNLO, LHEweight_AsMZ_Dn_NNPDF31_NNLO);
    lheHandler_NNPDF31_NNLO->clear();
    lheHandler_NNPDF31_NLO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_NLO->extract();
    FillLHEWeights(lheHandler_NNPDF31_NLO, LHEweight_Scaled_NNPDF31_NLO, LHEweight_Original_NNPDF31_NLO, LHEweight_MemberZero_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO, LHEweight_PDFVariation_Up_NNPDF31_NLO, LHEweight_PDFVariation_Dn_NNPDF31_NLO, LHEweight_AsMZ_Up_NNPDF31_NLO, LHEweight_AsMZ_Dn_NNPDF31_NLO);
    lheHandler_NNPDF31_NLO->clear();
    lheHandler_NNPDF31_LO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_LO->extract();
    FillLHEWeights(lheHandler_NNPDF31_LO, LHEweight_Scaled_NNPDF31_LO, LHEweight_Original_NNPDF31_LO, LHEweight_MemberZero_NNPDF31_LO, LHEweight_QCDscale_muR1_muF1_NNPDF31_LO, LHEweight_QCDscale_muR1_muF2_NNPDF31_LO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO, LHEweight_QCDscale_muR2_muF1_NNPDF31_LO, LHEweight_QCDscale_muR2_muF2_NNPDF31_LO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO, LHEweight_PDFVariation_Up_NNPDF31_LO, LHEweight_PDFVariation_Dn_NNPDF31_LO, LHEweight_AsMZ_Up_NNPDF31_LO, LHEweight_AsMZ_Dn_NNPDF31_LO);
    lheHandler_NNPDF31_LO->clear();

    tree->Fill();
  }
}

void LHEWeightAnalyzer::FillLHEWeights(LHEHandler const* lheHandler, float& LHEweight_Scaled, float& LHEweight_Original, float& LHEweight_MemberZero, float& LHEweight_QCDscale_muR1_muF1, float& LHEweight_QCDscale_muR1_muF2, float& LHEweight_QCDscale_muR1_muF0p5, float& LHEweight_QCDscale_muR2_muF1, float& LHEweight_QCDscale_muR2_muF2, float& LHEweight_QCDscale_muR2_muF0p5, float& LHEweight_QCDscale_muR0p5_muF1, float& LHEweight_QCDscale_muR0p5_muF2, float& LHEweight_QCDscale_muR0p5_muF0p5, float& LHEweight_PDFVariation_Up, float& LHEweight_PDFVariation_Dn, float& LHEweight_AsMZ_Up, float& LHEweight_AsMZ_Dn){
  LHEweight_Original = lheHandler->getLHEOriginalWeight();
  LHEweight_Scaled = LHEweight_Original*lheHandler->getWeightRescale();
  LHEweight_MemberZero = lheHandler->getMemberZeroWeight();
  LHEweight_QCDscale_muR1_muF1 = lheHandler->getLHEWeight(0, 1.);
  LHEweight_QCDscale_muR1_muF2 = lheHandler->getLHEWeight(1, 1.);
  LHEweight_QCDscale_muR1_muF0p5 = lheHandler->getLHEWeight(2, 1.);
  LHEweight_QCDscale_muR2_muF1 = lheHandler->getLHEWeight(3, 1.);
  LHEweight_QCDscale_muR2_muF2 = lheHandler->getLHEWeight(4, 1.);
  LHEweight_QCDscale_muR2_muF0p5 = lheHandler->getLHEWeight(5, 1.);
  LHEweight_QCDscale_muR0p5_muF1 = lheHandler->getLHEWeight(6, 1.);
  LHEweight_QCDscale_muR0p5_muF2 = lheHandler->getLHEWeight(7, 1.);
  LHEweight_QCDscale_muR0p5_muF0p5 = lheHandler->getLHEWeight(8, 1.);
  LHEweight_PDFVariation_Up = lheHandler->getLHEWeight_PDFVariationUpDn(1, 1.);
  LHEweight_PDFVariation_Dn = lheHandler->getLHEWeight_PDFVariationUpDn(-1, 1.);
  LHEweight_AsMZ_Up = lheHandler->getLHEWeigh_AsMZUpDn(1, 1.);
  LHEweight_AsMZ_Dn = lheHandler->getLHEWeigh_AsMZUpDn(-1, 1.);
}

void LHEWeightAnalyzer::beginJob(){
  edm::Service<TFileService> fs;
  TTree* tree = fs->make<TTree>(theTreeName, "Event Summary");

  tree->SetBranchAddress("LHEweight_Original_NNPDF30_NNLO", &LHEweight_Original_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF30_NNLO", &LHEweight_Scaled_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF30_NNLO", &LHEweight_MemberZero_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF30_NNLO", &LHEweight_PDFVariation_Up_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF30_NNLO", &LHEweight_PDFVariation_Dn_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF30_NNLO", &LHEweight_AsMZ_Up_NNPDF30_NNLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF30_NNLO", &LHEweight_AsMZ_Dn_NNPDF30_NNLO);

  tree->SetBranchAddress("LHEweight_Original_NNPDF30_NLO", &LHEweight_Original_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF30_NLO", &LHEweight_Scaled_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF30_NLO", &LHEweight_MemberZero_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF30_NLO", &LHEweight_PDFVariation_Up_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF30_NLO", &LHEweight_PDFVariation_Dn_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF30_NLO", &LHEweight_AsMZ_Up_NNPDF30_NLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF30_NLO", &LHEweight_AsMZ_Dn_NNPDF30_NLO);

  tree->SetBranchAddress("LHEweight_Original_NNPDF30_LO", &LHEweight_Original_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF30_LO", &LHEweight_Scaled_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF30_LO", &LHEweight_MemberZero_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF30_LO", &LHEweight_PDFVariation_Up_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF30_LO", &LHEweight_PDFVariation_Dn_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF30_LO", &LHEweight_AsMZ_Up_NNPDF30_LO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF30_LO", &LHEweight_AsMZ_Dn_NNPDF30_LO);

  tree->SetBranchAddress("LHEweight_Original_NNPDF31_NNLO", &LHEweight_Original_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF31_NNLO", &LHEweight_Scaled_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF31_NNLO", &LHEweight_MemberZero_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF31_NNLO", &LHEweight_PDFVariation_Up_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF31_NNLO", &LHEweight_PDFVariation_Dn_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF31_NNLO", &LHEweight_AsMZ_Up_NNPDF31_NNLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF31_NNLO", &LHEweight_AsMZ_Dn_NNPDF31_NNLO);

  tree->SetBranchAddress("LHEweight_Original_NNPDF31_NLO", &LHEweight_Original_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF31_NLO", &LHEweight_Scaled_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF31_NLO", &LHEweight_MemberZero_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF31_NLO", &LHEweight_PDFVariation_Up_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF31_NLO", &LHEweight_PDFVariation_Dn_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF31_NLO", &LHEweight_AsMZ_Up_NNPDF31_NLO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF31_NLO", &LHEweight_AsMZ_Dn_NNPDF31_NLO);

  tree->SetBranchAddress("LHEweight_Original_NNPDF31_LO", &LHEweight_Original_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_Scaled_NNPDF31_LO", &LHEweight_Scaled_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_MemberZero_NNPDF31_LO", &LHEweight_MemberZero_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Up_NNPDF31_LO", &LHEweight_PDFVariation_Up_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_PDFVariation_Dn_NNPDF31_LO", &LHEweight_PDFVariation_Dn_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_AsMZ_Up_NNPDF31_LO", &LHEweight_AsMZ_Up_NNPDF31_LO);
  tree->SetBranchAddress("LHEweight_AsMZ_Dn_NNPDF31_LO", &LHEweight_AsMZ_Dn_NNPDF31_LO);
}

// ------------ method called once each job just after ending the event loop  ------------
void LHEWeightAnalyzer::endJob(){}

// ------------ method called when starting to processes a run  ------------
void LHEWeightAnalyzer::beginRun(edm::Run const& iRun, edm::EventSetup const&){}

// ------------ method called when ending the processing of a run  ------------
void LHEWeightAnalyzer::endRun(edm::Run const& iRun, edm::EventSetup const&){}
