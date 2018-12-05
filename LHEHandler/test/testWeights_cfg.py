import FWCore.ParameterSet.Config as cms

process = cms.Process("testLHEWeights")


procname = "TTToHadronic_2018"
fNames = None
if procname == "WWZ_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8/MINIAODSIM/94X_mc2017_realistic_v11-v1/100000/4231F556-3A26-E811-AB1D-002590D60038.root')
elif procname == "ggTo4eContin_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/GluGluToContinToZZTo4e_13TeV_MCFM701_pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/00000/CEE57585-15FC-E711-87A0-0CC47AD98D06.root')
elif procname == "VBFH2000_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/VBF_HToZZTo4L_M2000_13TeV_powheg2_JHUGenV7011_pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v2/00000/5CADB5C5-B404-E811-B7E0-002590D9D8B2.root')
elif procname == "DYJetsToLL_M50_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/50000/7642F20E-30DC-E711-9548-0025905A60B8.root')
elif procname == "DYJetsToLL_M-4to50_HT-400to600_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v2/80000/FCF2C9A0-B605-E811-8B19-008CFAC93F4C.root')
elif procname == "tZq_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAODv2/tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/20000/041438B1-3C41-E811-BF9B-0025905B85DE.root')

elif procname == "WWZ_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/50000/B814DCC1-18B7-E611-AD77-0CC47AD98F68.root')
elif procname == "VBFH2000_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/VBF_HToZZTo4L_M2500_13TeV_powheg2_JHUgenV698_pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/50000/F41652E3-EDD4-E611-9B03-001E67397DF5.root')
elif procname == "DYJetsToLL_M50_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/90000/FE8A7852-66E4-E611-B5D0-002590E7E01A.root')
elif procname == "DYJetsToLL_M-5to50_HT-70to100_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/DYJetsToLL_M-5to50_HT-70to100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/90000/E678AB87-12F0-E611-92D5-02163E014428.root')
elif procname == "DY3JetsToLL_M-10to50_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/DY3JetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/0414608F-FAC9-E611-83FC-0CC47A4D767E.root')
elif procname == "tZq_2016":
  fNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv2/tZq_ll_4f_ckm_NLO_13TeV-amcatnlo-herwigpp/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/90000/FE94710A-CA3D-E711-81F6-0242AC130004.root')

elif procname == "TTToHadronic_2018":
  fNames = cms.untracked.vstring('/store/mc/RunIIAutumn18MiniAOD/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/60000/84347EC0-60B4-5145-8F92-37F1975CA79D.root')


theYear = None
if "2018" in procname:
   theYear=2018
elif "2017" in procname:
   theYear=2017
elif "2016" in procname:
   theYear=2016


process.source = cms.Source("PoolSource",
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
    fileNames = fNames,
    noEventSort = cms.untracked.bool(True),
    secondaryFileNames = cms.untracked.vstring()
)
process.CondDB = cms.PSet(
    DBParameters = cms.PSet(
        authenticationPath = cms.untracked.string(''),
        authenticationSystem = cms.untracked.int32(0),
        messageLevel = cms.untracked.int32(0),
        security = cms.untracked.string('')
    ),
    connect = cms.string('')
)

process.OutTree = cms.EDAnalyzer("LHEWeightAnalyzer",
    year = cms.int32(theYear),
)

#process.MessageLogger = cms.Service("MessageLogger",
    #FrameworkJobReport = cms.untracked.PSet(
        #FwkJob = cms.untracked.PSet(
            #limit = cms.untracked.int32(10000000),
            #optionalPSet = cms.untracked.bool(True)
        #),
        #default = cms.untracked.PSet(
            #limit = cms.untracked.int32(0)
        #),
        #optionalPSet = cms.untracked.bool(True)
    #),
    #categories = cms.untracked.vstring('FwkJob',
        #'FwkReport',
        #'FwkSummary',
        #'Root_NoDictionary'),
    #cerr = cms.untracked.PSet(
        #FwkJob = cms.untracked.PSet(
            #limit = cms.untracked.int32(0),
            #optionalPSet = cms.untracked.bool(True)
        #),
        #FwkReport = cms.untracked.PSet(
            #limit = cms.untracked.int32(10000000),
            #optionalPSet = cms.untracked.bool(True),
            #reportEvery = cms.untracked.int32(1000)
        #),
        #FwkSummary = cms.untracked.PSet(
            #limit = cms.untracked.int32(10000000),
            #optionalPSet = cms.untracked.bool(True),
            #reportEvery = cms.untracked.int32(1)
        #),
        #INFO = cms.untracked.PSet(
            #limit = cms.untracked.int32(0)
        #),
        #Root_NoDictionary = cms.untracked.PSet(
            #limit = cms.untracked.int32(0),
            #optionalPSet = cms.untracked.bool(True)
        #),
        #default = cms.untracked.PSet(
            #limit = cms.untracked.int32(10000000)
        #),
        #noTimeStamps = cms.untracked.bool(False),
        #optionalPSet = cms.untracked.bool(True),
        #threshold = cms.untracked.string('INFO')
    #),
    #cerr_stats = cms.untracked.PSet(
        #optionalPSet = cms.untracked.bool(True),
        #output = cms.untracked.string('cerr'),
        #threshold = cms.untracked.string('WARNING')
    #),
    #cout = cms.untracked.PSet(
        #placeholder = cms.untracked.bool(True)
    #),
    #debugModules = cms.untracked.vstring(),
    #debugs = cms.untracked.PSet(
        #placeholder = cms.untracked.bool(True)
    #),
    #default = cms.untracked.PSet(

    #),
    #destinations = cms.untracked.vstring('warnings',
        #'errors',
        #'infos',
        #'debugs',
        #'cout',
        #'cerr'),
    #errors = cms.untracked.PSet(
        #placeholder = cms.untracked.bool(True)
    #),
    #fwkJobReports = cms.untracked.vstring('FrameworkJobReport'),
    #infos = cms.untracked.PSet(
        #Root_NoDictionary = cms.untracked.PSet(
            #limit = cms.untracked.int32(0),
            #optionalPSet = cms.untracked.bool(True)
        #),
        #optionalPSet = cms.untracked.bool(True),
        #placeholder = cms.untracked.bool(True)
    #),
    #statistics = cms.untracked.vstring('cerr_stats'),
    #suppressDebug = cms.untracked.vstring(),
    #suppressInfo = cms.untracked.vstring(),
    #suppressWarning = cms.untracked.vstring(),
    #warnings = cms.untracked.PSet(
        #placeholder = cms.untracked.bool(True)
    #)
#)
process.MessageLogger = cms.Service("MessageLogger",
   destinations = cms.untracked.vstring(
      'cout',
      'cerr'
   ),
   cout = cms.untracked.PSet(
      threshold = cms.untracked.string('INFO')
   ),
   cerr = cms.untracked.PSet(
      threshold = cms.untracked.string('ERROR')
   )
)


process.TFileService = cms.Service("TFileService",
    fileName = cms.string(procname + '.root')
)

process.trees = cms.EndPath(process.OutTree)

