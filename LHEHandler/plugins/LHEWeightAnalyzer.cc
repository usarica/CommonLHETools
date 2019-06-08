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

float LHEweight_Scaled_DefaultPDF; float LHEweight_Original_DefaultPDF; float LHEweight_MemberZero_DefaultPDF; float LHEweight_QCDscale_muR1_muF1_DefaultPDF; float LHEweight_QCDscale_muR1_muF2_DefaultPDF; float LHEweight_QCDscale_muR1_muF0p5_DefaultPDF; float LHEweight_QCDscale_muR2_muF1_DefaultPDF; float LHEweight_QCDscale_muR2_muF2_DefaultPDF; float LHEweight_QCDscale_muR2_muF0p5_DefaultPDF; float LHEweight_QCDscale_muR0p5_muF1_DefaultPDF; float LHEweight_QCDscale_muR0p5_muF2_DefaultPDF; float LHEweight_QCDscale_muR0p5_muF0p5_DefaultPDF; float LHEweight_PDFVariation_Up_DefaultPDF; float LHEweight_PDFVariation_Dn_DefaultPDF; float LHEweight_AsMZ_Up_DefaultPDF; float LHEweight_AsMZ_Dn_DefaultPDF;

float LHEweight_Scaled_NNPDF30_LO; float LHEweight_Original_NNPDF30_LO; float LHEweight_MemberZero_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_LO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_LO; float LHEweight_PDFVariation_Up_NNPDF30_LO; float LHEweight_PDFVariation_Dn_NNPDF30_LO; float LHEweight_AsMZ_Up_NNPDF30_LO; float LHEweight_AsMZ_Dn_NNPDF30_LO;
float LHEweight_Scaled_NNPDF30_NLO; float LHEweight_Original_NNPDF30_NLO; float LHEweight_MemberZero_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NLO; float LHEweight_PDFVariation_Up_NNPDF30_NLO; float LHEweight_PDFVariation_Dn_NNPDF30_NLO; float LHEweight_AsMZ_Up_NNPDF30_NLO; float LHEweight_AsMZ_Dn_NNPDF30_NLO;
float LHEweight_Scaled_NNPDF30_NNLO; float LHEweight_Original_NNPDF30_NNLO; float LHEweight_MemberZero_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF30_NNLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF30_NNLO; float LHEweight_PDFVariation_Up_NNPDF30_NNLO; float LHEweight_PDFVariation_Dn_NNPDF30_NNLO; float LHEweight_AsMZ_Up_NNPDF30_NNLO; float LHEweight_AsMZ_Dn_NNPDF30_NNLO;

float LHEweight_Scaled_NNPDF31_LO; float LHEweight_Original_NNPDF31_LO; float LHEweight_MemberZero_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_LO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_LO; float LHEweight_PDFVariation_Up_NNPDF31_LO; float LHEweight_PDFVariation_Dn_NNPDF31_LO; float LHEweight_AsMZ_Up_NNPDF31_LO; float LHEweight_AsMZ_Dn_NNPDF31_LO;
float LHEweight_Scaled_NNPDF31_NLO; float LHEweight_Original_NNPDF31_NLO; float LHEweight_MemberZero_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NLO; float LHEweight_PDFVariation_Up_NNPDF31_NLO; float LHEweight_PDFVariation_Dn_NNPDF31_NLO; float LHEweight_AsMZ_Up_NNPDF31_NLO; float LHEweight_AsMZ_Dn_NNPDF31_NLO;
float LHEweight_Scaled_NNPDF31_NNLO; float LHEweight_Original_NNPDF31_NNLO; float LHEweight_MemberZero_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR1_muF0p5_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR2_muF0p5_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF1_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF2_NNPDF31_NNLO; float LHEweight_QCDscale_muR0p5_muF0p5_NNPDF31_NNLO; float LHEweight_PDFVariation_Up_NNPDF31_NNLO; float LHEweight_PDFVariation_Dn_NNPDF31_NNLO; float LHEweight_AsMZ_Up_NNPDF31_NNLO; float LHEweight_AsMZ_Dn_NNPDF31_NNLO;

unsigned int ntops;
std::vector<float> tops_pt, tops_eta, tops_phi, tops_mass;


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

  virtual void FillLHEWeights(std::unique_ptr<LHEHandler> const& lheHandler, float& LHEweight_Scaled, float& LHEweight_Original, float& LHEweight_MemberZero, float& LHEweight_QCDscale_muR1_muF1, float& LHEweight_QCDscale_muR1_muF2, float& LHEweight_QCDscale_muR1_muF0p5, float& LHEweight_QCDscale_muR2_muF1, float& LHEweight_QCDscale_muR2_muF2, float& LHEweight_QCDscale_muR2_muF0p5, float& LHEweight_QCDscale_muR0p5_muF1, float& LHEweight_QCDscale_muR0p5_muF2, float& LHEweight_QCDscale_muR0p5_muF0p5, float& LHEweight_PDFVariation_Up, float& LHEweight_PDFVariation_Dn, float& LHEweight_AsMZ_Up, float& LHEweight_AsMZ_Dn);

  // ----------member data ---------------------------
  int year;
  LHEHandler::KinematicsMode kinMode;
  TString theTreeName;
  TTree* tree;
  std::unique_ptr<LHEHandler> lheHandler_DefaultPDF;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF30_NNLO;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF30_NLO;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF30_LO;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF31_NNLO;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF31_NLO;
  std::unique_ptr<LHEHandler> lheHandler_NNPDF31_LO;

  edm::EDGetTokenT<LHERunInfoProduct> lheRunInfoToken;
  edm::EDGetTokenT<GenEventInfoProduct> genInfoToken;

};



LHEWeightAnalyzer::LHEWeightAnalyzer(const edm::ParameterSet& pset) :
  year(pset.getParameter<int>("year")),
  kinMode((LHEHandler::KinematicsMode) pset.getParameter<int>("kinMode")),
  theTreeName("weightsTree"),
  tree(nullptr)
{
  consumesMany<LHEEventProduct>();
  lheRunInfoToken = consumes<LHERunInfoProduct, edm::InRun>(edm::InputTag("externalLHEProducer"));
  genInfoToken = consumes<GenEventInfoProduct>(edm::InputTag("generator"));

  if (year==2016) LHEHandler::set_maxlines_print_header(1000);
  else LHEHandler::set_maxlines_print_header(-1);

  lheHandler_DefaultPDF = std::make_unique<LHEHandler>(
    -1, -1,
    kinMode,
    year, LHEHandler::keepDefaultPDF, LHEHandler::keepDefaultQCDOrder
  );
  lheHandler_NNPDF30_NNLO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF30, LHEHandler::tryNNLO
  );
  lheHandler_NNPDF30_NLO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF30, LHEHandler::tryNLO
  );
  lheHandler_NNPDF30_LO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF30, LHEHandler::tryLO
  );
  lheHandler_NNPDF31_NNLO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF31, LHEHandler::tryNNLO
  );
  lheHandler_NNPDF31_NLO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF31, LHEHandler::tryNLO
  );
  lheHandler_NNPDF31_LO = std::make_unique<LHEHandler>(
    -1, -1,
    LHEHandler::noKinematics,
    year, LHEHandler::tryNNPDF31, LHEHandler::tryLO
  );
}

LHEWeightAnalyzer::~LHEWeightAnalyzer(){
  // No need to delete unique_ptrs
}


void LHEWeightAnalyzer::analyze(const edm::Event& event, const edm::EventSetup& eSetup){
  // LHE information
  vector<edm::Handle<LHEEventProduct> > lhe_handles;
  event.getManyByType(lhe_handles);
  
  edm::Handle<GenEventInfoProduct> gen_handle;
  event.getByToken(genInfoToken, gen_handle);

  static bool firstEvent=true;
  if (!lhe_handles.empty()){
    //std::cout << "New ev!" << std::endl;
    edm::Handle<LHEEventProduct>& lhe_evt = lhe_handles.front();
    //std::cout << "New hndl!" << std::endl;

    lheHandler_DefaultPDF->setHandle(&lhe_evt);
    lheHandler_DefaultPDF->extract();
    FillLHEWeights(lheHandler_DefaultPDF, LHEweight_Scaled_DefaultPDF, LHEweight_Original_DefaultPDF, LHEweight_MemberZero_DefaultPDF, LHEweight_QCDscale_muR1_muF1_DefaultPDF, LHEweight_QCDscale_muR1_muF2_DefaultPDF, LHEweight_QCDscale_muR1_muF0p5_DefaultPDF, LHEweight_QCDscale_muR2_muF1_DefaultPDF, LHEweight_QCDscale_muR2_muF2_DefaultPDF, LHEweight_QCDscale_muR2_muF0p5_DefaultPDF, LHEweight_QCDscale_muR0p5_muF1_DefaultPDF, LHEweight_QCDscale_muR0p5_muF2_DefaultPDF, LHEweight_QCDscale_muR0p5_muF0p5_DefaultPDF, LHEweight_PDFVariation_Up_DefaultPDF, LHEweight_PDFVariation_Dn_DefaultPDF, LHEweight_AsMZ_Up_DefaultPDF, LHEweight_AsMZ_Dn_DefaultPDF);
    
    // Special case for this handler is to fill the event kinematics
    if (kinMode!=LHEHandler::noKinematics){
      MELAEvent* genEvent = lheHandler_DefaultPDF->getEvent();
      for (auto const* top:genEvent->getTopCandidates()){
        if (!top->passSelection) continue;
        tops_pt.push_back(top->pt());
        tops_eta.push_back(top->eta());
        tops_phi.push_back(top->phi());
        tops_mass.push_back(top->m());
      }
      ntops=tops_mass.size();
    }

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
    if (kinMode!=LHEHandler::noKinematics){
      tops_pt.clear(); tops_eta.clear(); tops_phi.clear(); tops_mass.clear();
    }
  }
  else if (firstEvent){
    edm::LogWarning warning("InvalidLHEHandle");
    warning << "LHEEventProduct is invalid!";
  }

  if (firstEvent) firstEvent=false;
}

void LHEWeightAnalyzer::FillLHEWeights(std::unique_ptr<LHEHandler> const& lheHandler, float& LHEweight_Scaled, float& LHEweight_Original, float& LHEweight_MemberZero, float& LHEweight_QCDscale_muR1_muF1, float& LHEweight_QCDscale_muR1_muF2, float& LHEweight_QCDscale_muR1_muF0p5, float& LHEweight_QCDscale_muR2_muF1, float& LHEweight_QCDscale_muR2_muF2, float& LHEweight_QCDscale_muR2_muF0p5, float& LHEweight_QCDscale_muR0p5_muF1, float& LHEweight_QCDscale_muR0p5_muF2, float& LHEweight_QCDscale_muR0p5_muF0p5, float& LHEweight_PDFVariation_Up, float& LHEweight_PDFVariation_Dn, float& LHEweight_AsMZ_Up, float& LHEweight_AsMZ_Dn){
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

  tree->Branch("LHEweight_Original_DefaultPDF", &LHEweight_Original_DefaultPDF);
  tree->Branch("LHEweight_Scaled_DefaultPDF", &LHEweight_Scaled_DefaultPDF);
  tree->Branch("LHEweight_MemberZero_DefaultPDF", &LHEweight_MemberZero_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR1_muF1_DefaultPDF", &LHEweight_QCDscale_muR1_muF1_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR1_muF2_DefaultPDF", &LHEweight_QCDscale_muR1_muF2_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR1_muF0p5_DefaultPDF", &LHEweight_QCDscale_muR1_muF0p5_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR2_muF1_DefaultPDF", &LHEweight_QCDscale_muR2_muF1_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR2_muF2_DefaultPDF", &LHEweight_QCDscale_muR2_muF2_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR2_muF0p5_DefaultPDF", &LHEweight_QCDscale_muR2_muF0p5_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF1_DefaultPDF", &LHEweight_QCDscale_muR0p5_muF1_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF2_DefaultPDF", &LHEweight_QCDscale_muR0p5_muF2_DefaultPDF);
  tree->Branch("LHEweight_QCDscale_muR0p5_muF0p5_DefaultPDF", &LHEweight_QCDscale_muR0p5_muF0p5_DefaultPDF);
  tree->Branch("LHEweight_PDFVariation_Up_DefaultPDF", &LHEweight_PDFVariation_Up_DefaultPDF);
  tree->Branch("LHEweight_PDFVariation_Dn_DefaultPDF", &LHEweight_PDFVariation_Dn_DefaultPDF);
  tree->Branch("LHEweight_AsMZ_Up_DefaultPDF", &LHEweight_AsMZ_Up_DefaultPDF);
  tree->Branch("LHEweight_AsMZ_Dn_DefaultPDF", &LHEweight_AsMZ_Dn_DefaultPDF);

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

  if (kinMode == LHEHandler::doBasicKinematics){
    tree->Branch("ntops", &ntops);
    tree->Branch("tops_pt", &tops_pt);
    tree->Branch("tops_eta", &tops_eta);
    tree->Branch("tops_phi", &tops_phi);
    tree->Branch("tops_mass", &tops_mass);
  }

}

// ------------ method called once each job just after ending the event loop  ------------
void LHEWeightAnalyzer::endJob(){}

// ------------ method called when starting to process a run  ------------
void LHEWeightAnalyzer::beginRun(edm::Run const& iRun, edm::EventSetup const&){
  static bool firstRun=true;
  if (firstRun){
    edm::Handle<LHERunInfoProduct> lhe_runinfo;
    iRun.getByLabel(edm::InputTag("externalLHEProducer"), lhe_runinfo);
    lheHandler_DefaultPDF->setHeaderFromRunInfo(&lhe_runinfo);
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
