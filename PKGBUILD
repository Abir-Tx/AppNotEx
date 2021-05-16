
# Maintainer: Abir-Tx <abirtx@yandex.com>
pkgname=appnotex
pkgver=0.9.0
pkgrel=1
pkgdesc="Quick terminal based note keeper for Linux Apps"
arch=(x86_64)
url="https://github.com/Abir-Tx/AppNotEx.git"
license=('GPL')
depends=(sqlite3)
makedepends=(git make cmake)
checkdepends=()
optdepends=()
provides=(appnotex)
conflicts=(appnotex)
replaces=()
backup=()
options=()
install=
changelog=
source=("git+$url")
md5sums=('SKIP')
validpgpkeys=()

build() {
	cd AppNotEx
	git submodule init && git submodule update
	make builddir
	cd build
	cmake ..
	make appnotex
}

package() {
	cd AppNotEx
	cd build
	sudo make install

	cd ..
	install -Dm644 -v README.md "${pkgdir}/usr/share/doc/${pkgname}/README.md"
	install -Dm644 -v LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}