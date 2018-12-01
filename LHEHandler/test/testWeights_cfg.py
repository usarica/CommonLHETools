import FWCore.ParameterSet.Config as cms

process = cms.Process("testLHEWeights")


procname = "tZq_2017"
fNames = None
if procname == "WWZ_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8/MINIAODSIM/94X_mc2017_realistic_v11-v1/100000/4231F556-3A26-E811-AB1D-002590D60038.root')
elif procname == "ggTo4eContin_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/GluGluToContinToZZTo4e_13TeV_MCFM701_pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/00000/CEE57585-15FC-E711-87A0-0CC47AD98D06.root')
elif procname == "VBFH2000_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/VBF_HToZZTo4L_M2000_13TeV_powheg2_JHUGenV7011_pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v2/00000/5CADB5C5-B404-E811-B7E0-002590D9D8B2.root')
elif procname == "DYJetsToLL_M50_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAOD/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/50000/7642F20E-30DC-E711-9548-0025905A60B8.root')
elif procname == "tZq_2017":
  fNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAODv2/tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/20000/041438B1-3C41-E811-BF9B-0025905B85DE.root')


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
    year = cms.int32(2017),
)

process.MessageLogger = cms.Service("MessageLogger",
    FrameworkJobReport = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        optionalPSet = cms.untracked.bool(True)
    ),
    categories = cms.untracked.vstring('FwkJob',
        'FwkReport',
        'FwkSummary',
        'Root_NoDictionary'),
    cerr = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        FwkReport = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1000)
        ),
        FwkSummary = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1)
        ),
        INFO = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000)
        ),
        noTimeStamps = cms.untracked.bool(False),
        optionalPSet = cms.untracked.bool(True),
        threshold = cms.untracked.string('INFO')
    ),
    cerr_stats = cms.untracked.PSet(
        optionalPSet = cms.untracked.bool(True),
        output = cms.untracked.string('cerr'),
        threshold = cms.untracked.string('WARNING')
    ),
    cout = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    debugModules = cms.untracked.vstring(),
    debugs = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    default = cms.untracked.PSet(

    ),
    destinations = cms.untracked.vstring('warnings',
        'errors',
        'infos',
        'debugs',
        'cout',
        'cerr'),
    errors = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    fwkJobReports = cms.untracked.vstring('FrameworkJobReport'),
    infos = cms.untracked.PSet(
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        optionalPSet = cms.untracked.bool(True),
        placeholder = cms.untracked.bool(True)
    ),
    statistics = cms.untracked.vstring('cerr_stats'),
    suppressDebug = cms.untracked.vstring(),
    suppressInfo = cms.untracked.vstring(),
    suppressWarning = cms.untracked.vstring(),
    warnings = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    )
)


process.TFileService = cms.Service("TFileService",
    fileName = cms.string(procname + '.root')
)

process.trees = cms.EndPath(process.OutTree)

