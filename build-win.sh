# build
cd depends
chown +x config.*
make HOST=x86_64-w64-mingw32
cd ..
chmod +x *.sh
./autogen.sh # not required when building from tarball
CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/
make
