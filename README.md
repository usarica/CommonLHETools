# CommonLHETools
Common LHE tools for HIG and SUS analyses

Checkout instructions:

git cms-init

# MELA Analytics
git clone https://github.com/usarica/MelaAnalytics.git
(cd MelaAnalytics; git checkout -b from-v11 v1.1)

# MELA
git clone https://github.com/cms-analysis/HiggsAnalysis-ZZMatrixElement.git ZZMatrixElement
(cd ZZMatrixElement; git checkout -b from-v217b1 v2.1.7b1; source setup.sh -j 12;)

# Common LHE tools
git clone https://github.com/usarica/CommonLHETools.git
(cd CommonLHETools; git checkout -b from-v12 v1.2)
