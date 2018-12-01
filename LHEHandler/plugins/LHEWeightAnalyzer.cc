#include <memory>
#include <cmath>
#include <algorithm>

#include <FWCore/Framework/interface/EDAnalyzer.h>
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Run.h"
#include <FWCore/Framework/interface/MakerMacros.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <FWCore/MessageLogger/interface/MessageLogger.h>
#include <FWCore/ServiceRegistry/interface/Service.h>
#include <CommonTools/UtilAlgos/interface/TFileService.h>

#include <CommonLHETools/LHEHandler/interface/LHEHandler.h>
#include <SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h>

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
class LHEWeightAnalyzer : public edm::EDAnalyzer{
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
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken;

};



LHEWeightAnalyzer::LHEWeightAnalyzer(const edm::ParameterSet& pset) :
  year(pset.getParameter<int>("year")),
  theTreeName("weightsTree"),
  tree(nullptr)
{
  consumesMany<LHEEventProduct>();
  lheRunInfoToken = consumes<LHERunInfoProduct, edm::InRun>(edm::InputTag("externalLHEProducer"));
  genInfoToken = consumes<GenEventInfoProduct>(edm::InputTag("generator"));

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
  vector<edm::Handle<LHEEventProduct> > lhe_handles;
  event.getManyByType(lhe_handles);
  
  edm::Handle<GenEventInfoProduct> gen_handle;
  event.getByToken(genInfoToken, gen_handle);

  if (!lhe_handles.empty()){
    //std::cout << "New ev!" << std::endl;
    edm::Handle<LHEEventProduct>& lhe_evt = lhe_handles.front();
    //std::cout << "New hndl!" << std::endl;

    lheHandler_NNPDF30_NNLO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_NNLO->extract();
    FillLHEWeights(lheHandler_NNPDF30_NNLO, LHEweight_Scaled_NNPDF30_NNLO, LHEweight_Original_NNPDF30_NNLO, LHEweight_MemberZero_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO, LHEweight_PDFVariation_Up_NNPDF30_NNLO, LHEweight_PDFVariation_Dn_NNPDF30_NNLO, LHEweight_AsMZ_Up_NNPDF30_NNLO, LHEweight_AsMZ_Dn_NNPDF30_NNLO);
    lheHandler_NNPDF30_NNLO->clear();
    //std::cout << "lheHandler_NNPDF30_NNLO done" << std::endl;
    lheHandler_NNPDF30_NLO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_NLO->extract();
    FillLHEWeights(lheHandler_NNPDF30_NLO, LHEweight_Scaled_NNPDF30_NLO, LHEweight_Original_NNPDF30_NLO, LHEweight_MemberZero_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO, LHEweight_PDFVariation_Up_NNPDF30_NLO, LHEweight_PDFVariation_Dn_NNPDF30_NLO, LHEweight_AsMZ_Up_NNPDF30_NLO, LHEweight_AsMZ_Dn_NNPDF30_NLO);
    lheHandler_NNPDF30_NLO->clear();
    //std::cout << "lheHandler_NNPDF30_NLO done" << std::endl;
    lheHandler_NNPDF30_LO->setHandle(&lhe_evt);
    lheHandler_NNPDF30_LO->extract();
    FillLHEWeights(lheHandler_NNPDF30_LO, LHEweight_Scaled_NNPDF30_LO, LHEweight_Original_NNPDF30_LO, LHEweight_MemberZero_NNPDF30_LO, LHEweight_QCDscale_muR1_muF1_NNPDF30_LO, LHEweight_QCDscale_muR1_muF2_NNPDF30_LO, LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO, LHEweight_QCDscale_muR2_muF1_NNPDF30_LO, LHEweight_QCDscale_muR2_muF2_NNPDF30_LO, LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO, LHEweight_PDFVariation_Up_NNPDF30_LO, LHEweight_PDFVariation_Dn_NNPDF30_LO, LHEweight_AsMZ_Up_NNPDF30_LO, LHEweight_AsMZ_Dn_NNPDF30_LO);
    lheHandler_NNPDF30_LO->clear();
    //std::cout << "lheHandler_NNPDF30_LO done" << std::endl;
    lheHandler_NNPDF31_NNLO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_NNLO->extract();
    FillLHEWeights(lheHandler_NNPDF31_NNLO, LHEweight_Scaled_NNPDF31_NNLO, LHEweight_Original_NNPDF31_NNLO, LHEweight_MemberZero_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO, LHEweight_PDFVariation_Up_NNPDF31_NNLO, LHEweight_PDFVariation_Dn_NNPDF31_NNLO, LHEweight_AsMZ_Up_NNPDF31_NNLO, LHEweight_AsMZ_Dn_NNPDF31_NNLO);
    lheHandler_NNPDF31_NNLO->clear();
    //std::cout << "lheHandler_NNPDF31_NNLO done" << std::endl;
    lheHandler_NNPDF31_NLO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_NLO->extract();
    FillLHEWeights(lheHandler_NNPDF31_NLO, LHEweight_Scaled_NNPDF31_NLO, LHEweight_Original_NNPDF31_NLO, LHEweight_MemberZero_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO, LHEweight_PDFVariation_Up_NNPDF31_NLO, LHEweight_PDFVariation_Dn_NNPDF31_NLO, LHEweight_AsMZ_Up_NNPDF31_NLO, LHEweight_AsMZ_Dn_NNPDF31_NLO);
    lheHandler_NNPDF31_NLO->clear();
    //std::cout << "lheHandler_NNPDF31_NLO done" << std::endl;
    lheHandler_NNPDF31_LO->setHandle(&lhe_evt);
    lheHandler_NNPDF31_LO->extract();
    FillLHEWeights(lheHandler_NNPDF31_LO, LHEweight_Scaled_NNPDF31_LO, LHEweight_Original_NNPDF31_LO, LHEweight_MemberZero_NNPDF31_LO, LHEweight_QCDscale_muR1_muF1_NNPDF31_LO, LHEweight_QCDscale_muR1_muF2_NNPDF31_LO, LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO, LHEweight_QCDscale_muR2_muF1_NNPDF31_LO, LHEweight_QCDscale_muR2_muF2_NNPDF31_LO, LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO, LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO, LHEweight_PDFVariation_Up_NNPDF31_LO, LHEweight_PDFVariation_Dn_NNPDF31_LO, LHEweight_AsMZ_Up_NNPDF31_LO, LHEweight_AsMZ_Dn_NNPDF31_LO);
    lheHandler_NNPDF31_LO->clear();
    //std::cout << "lheHandler_NNPDF31_LO done" << std::endl;

    tree->Fill();
    //std::cout << "Tree is filled!" << std::endl;
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
  tree = fs->make<TTree>(theTreeName, "Event Summary");

  tree->Branch("LHEweight_Original_NNPDF30_NNLO", &LHEweight_Original_NNPDF30_NNLO);
  tree->Branch("LHEweight_Scaled_NNPDF30_NNLO", &LHEweight_Scaled_NNPDF30_NNLO);
  tree->Branch("LHEweight_MemberZero_NNPDF30_NNLO", &LHEweight_MemberZero_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF30_NNLO", &LHEweight_PDFVariation_Up_NNPDF30_NNLO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF30_NNLO", &LHEweight_PDFVariation_Dn_NNPDF30_NNLO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF30_NNLO", &LHEweight_AsMZ_Up_NNPDF30_NNLO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF30_NNLO", &LHEweight_AsMZ_Dn_NNPDF30_NNLO);

  tree->Branch("LHEweight_Original_NNPDF30_NLO", &LHEweight_Original_NNPDF30_NLO);
  tree->Branch("LHEweight_Scaled_NNPDF30_NLO", &LHEweight_Scaled_NNPDF30_NLO);
  tree->Branch("LHEweight_MemberZero_NNPDF30_NLO", &LHEweight_MemberZero_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF30_NLO", &LHEweight_PDFVariation_Up_NNPDF30_NLO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF30_NLO", &LHEweight_PDFVariation_Dn_NNPDF30_NLO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF30_NLO", &LHEweight_AsMZ_Up_NNPDF30_NLO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF30_NLO", &LHEweight_AsMZ_Dn_NNPDF30_NLO);

  tree->Branch("LHEweight_Original_NNPDF30_LO", &LHEweight_Original_NNPDF30_LO);
  tree->Branch("LHEweight_Scaled_NNPDF30_LO", &LHEweight_Scaled_NNPDF30_LO);
  tree->Branch("LHEweight_MemberZero_NNPDF30_LO", &LHEweight_MemberZero_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF1_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF2_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF1_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF2_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF30_LO", &LHEweight_PDFVariation_Up_NNPDF30_LO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF30_LO", &LHEweight_PDFVariation_Dn_NNPDF30_LO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF30_LO", &LHEweight_AsMZ_Up_NNPDF30_LO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF30_LO", &LHEweight_AsMZ_Dn_NNPDF30_LO);

  tree->Branch("LHEweight_Original_NNPDF31_NNLO", &LHEweight_Original_NNPDF31_NNLO);
  tree->Branch("LHEweight_Scaled_NNPDF31_NNLO", &LHEweight_Scaled_NNPDF31_NNLO);
  tree->Branch("LHEweight_MemberZero_NNPDF31_NNLO", &LHEweight_MemberZero_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF31_NNLO", &LHEweight_PDFVariation_Up_NNPDF31_NNLO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF31_NNLO", &LHEweight_PDFVariation_Dn_NNPDF31_NNLO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF31_NNLO", &LHEweight_AsMZ_Up_NNPDF31_NNLO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF31_NNLO", &LHEweight_AsMZ_Dn_NNPDF31_NNLO);

  tree->Branch("LHEweight_Original_NNPDF31_NLO", &LHEweight_Original_NNPDF31_NLO);
  tree->Branch("LHEweight_Scaled_NNPDF31_NLO", &LHEweight_Scaled_NNPDF31_NLO);
  tree->Branch("LHEweight_MemberZero_NNPDF31_NLO", &LHEweight_MemberZero_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF31_NLO", &LHEweight_PDFVariation_Up_NNPDF31_NLO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF31_NLO", &LHEweight_PDFVariation_Dn_NNPDF31_NLO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF31_NLO", &LHEweight_AsMZ_Up_NNPDF31_NLO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF31_NLO", &LHEweight_AsMZ_Dn_NNPDF31_NLO);

  tree->Branch("LHEweight_Original_NNPDF31_LO", &LHEweight_Original_NNPDF31_LO);
  tree->Branch("LHEweight_Scaled_NNPDF31_LO", &LHEweight_Scaled_NNPDF31_LO);
  tree->Branch("LHEweight_MemberZero_NNPDF31_LO", &LHEweight_MemberZero_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF1_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF2_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF1_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF2_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO", &LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO);
  tree->Branch("LHEweight_PDFVariation_Up_NNPDF31_LO", &LHEweight_PDFVariation_Up_NNPDF31_LO);
  tree->Branch("LHEweight_PDFVariation_Dn_NNPDF31_LO", &LHEweight_PDFVariation_Dn_NNPDF31_LO);
  tree->Branch("LHEweight_AsMZ_Up_NNPDF31_LO", &LHEweight_AsMZ_Up_NNPDF31_LO);
  tree->Branch("LHEweight_AsMZ_Dn_NNPDF31_LO", &LHEweight_AsMZ_Dn_NNPDF31_LO);
}

// ------------ method called once each job just after ending the event loop  ------------
void LHEWeightAnalyzer::endJob(){}

// ------------ method called when starting to process a run  ------------
void LHEWeightAnalyzer::beginRun(edm::Run const& iRun, edm::EventSetup const&){
  static bool firstRun=true;
  if (firstRun){
    edm::Handle<LHERunInfoProduct> lhe_runinfo;
    iRun.getByLabel(edm::InputTag("externalLHEProducer"), lhe_runinfo);
    lheHandler_NNPDF30_NNLO->setHeaderFromRunInfo(&lhe_runinfo);
    lheHandler_NNPDF30_NLO->setHeaderFromRunInfo(&lhe_runinfo);
    lheHandler_NNPDF30_LO->setHeaderFromRunInfo(&lhe_runinfo);
    lheHandler_NNPDF31_NNLO->setHeaderFromRunInfo(&lhe_runinfo);
    lheHandler_NNPDF31_NLO->setHeaderFromRunInfo(&lhe_runinfo);
    lheHandler_NNPDF31_LO->setHeaderFromRunInfo(&lhe_runinfo);
    firstRun=false;
  }
}

// ------------ method called when ending to process a run  ------------
void LHEWeightAnalyzer::endRun(edm::Run const& iRun, edm::EventSetup const&){
  /*
  edm::Handle<LHERunInfoProduct> run;
  typedef std::vector<LHERunInfoProduct::Header>::const_iterator headers_const_iterator;
  iRun.getByToken(lheRunInfoToken, run);
  LHERunInfoProduct myLHERunInfoProduct = *(run.product());
  for (auto iter=myLHERunInfoProduct.headers_begin(); iter!=myLHERunInfoProduct.headers_end(); iter++){
    std::cout << iter->tag() << std::endl;
    std::vector<std::string> lines = iter->lines();
    for (unsigned int iLine = 0; iLine<lines.size(); iLine++) {
      std::cout << lines.at(iLine);
    }
  }
  */
}


DEFINE_FWK_MODULE(LHEWeightAnalyzer);
