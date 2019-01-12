### Automated Building
#steps to build picscoin
#------------------------
#dont use as a script input following commands 
#directly into the command prompt
#**input 1 line at a time
#download latest picscoin source
git clone https://github.com/minblock/picscoin 
#edit file picscoin/contrib/gitian-build.sh 
#set number of cores to use and ram
#currently set to 12 and 5000MB
#execute from your root home folder
export SIGNER=minblock
export VERSION=HEAD
picscoin/contrib/gitian-build.sh --setup -c $SIGNER $VERSION
