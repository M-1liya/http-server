mkdir -p ./deb_pakage
mkdir -p ./deb_pakage/bin
mkdir -p ./deb_pakage/DEBIAN
touch  ./deb_pakage/DEBIAN/control

cat << EOF > ./deb_pakage/DEBIAN/control
Package: http-server
Version: 1.0
Architecture: amd64
Depends: curl
Maintainer: M-1liya
Description: http server for DCSA labs
EOF

chmod 755 ./deb_pakage/DEBIAN/postinst
chmod 755 ./deb_pakage/DEBIAN/prerm

cp ./build/http-server ./deb_pakage/bin/

dpkg-deb --build ./deb_pakage/ http-server-dcsa.deb