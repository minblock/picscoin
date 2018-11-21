
# zip unix binaries
#mkdir -p ./bin/unix
#cp -v ./src/picscoind ./bin/unix/
#cp -v ./src/picscoin-cli ./bin/unix/
#cp -v ./src/picscoin-tx ./bin/unix/
#cp -v ./src/test/test_picscoin ./bin/unix/
#cp -v ./src/bench/bench_picscoin ./bin/unix/
#cp -v ./src/qt/picscoin-qt ./bin/unix
#cp -v ./src/qt/test/test_picscoin-qt ./bin/unix
#cp -v ./picscoin.conf ./bin/unix/
#zip ./bin/picscoin-unix.zip ./bin/unix/*

WIN_ZIP_FILENAME=picscoin-x86_64-win64-vx.zip
WIN_RELEASE_FOLDER=./bin/release-win64

# zip win64 binaries
mkdir -p $WIN_RELEASE_FOLDER
cp -v ./src/picscoin-cli.exe $WIN_RELEASE_FOLDER/
cp -v ./src/picscoind.exe $WIN_RELEASE_FOLDER/
cp -v ./src/bench/bench_picscoin.exe $WIN_RELEASE_FOLDER/
#cp -v ./src/test/test_picscoin.exe $WIN_RELEASE_FOLDER/
cp -v ./src/qt/picscoin-qt.exe $WIN_RELEASE_FOLDER/
#cp -v ./src/qt/test/test_picscoin-qt.exe $WIN_RELEASE_FOLDER/
cp -v ./src/picscoin-tx.exe $WIN_RELEASE_FOLDER/
cp -v ./picscoin.conf $WIN_RELEASE_FOLDER/
cp -v "./bin/common files/README.txt" $WIN_RELEASE_FOLDER
cp -v "./bin/common files/libbitcoinconsensus-0.dll" $WIN_RELEASE_FOLDER
cp -v "./bin/common files/mine.bat" $WIN_RELEASE_FOLDER
cp -v "./bin/common files/mine.sh" $WIN_RELEASE_FOLDER

cd $WIN_RELEASE_FOLDER
zip $WIN_ZIP_FILENAME *



