# Stuff applying to all ncams on image

require softcam.inc
inherit cmake

FILESEXTRAPATHS_prepend := "${THISDIR}/enigma2-plugin-softcams-ncam:"

SRC_URI += " \
            file://NCAM-LICENSE \
            file://init.ncam \
            file://${CAMNAME}/ \
"

LICENSE="GPLv3"
LIC_FILES_CHKSUM = "file://../NCAM-LICENSE;md5=d32239bcb673463ab874e80d47fae504"

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

PACKAGE_ARCH = "${DEFAULTTUNE}"

DEPENDS = "libusb openssl"

EXTRA_OECMAKE += "\
	-DWEBIF=1 \
	-DWEBIF_LIVELOG=1 \
	-DWEBIF_JQUERY=1 \
	-DTOUCH=1 \
	-DWITH_SSL=1 \
	-DWITH_STAPI=0 \
	-DHAVE_LIBUSB=1 \
	-DSTATIC_LIBUSB=0 \
"

do_configure_prepend () {
	cp ${S}/../init.ncam ${S}/init.${CAMNAME}
}

do_install () {
	install -d ${D}/${bindir}
	install -m 0755 ${WORKDIR}/build/ncam ${D}/usr/softcams/${CAMNAME}
	install -d ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}
	[[ -e ${S}/../${CAMNAME} ]] && install 644 ${S}/../${CAMNAME}/* ${D}/${sysconfdir}/tuxbox/config/${CAMNAME} 2>/dev/null || true
	[[ -e ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs ]] && rm ${D}/${sysconfdir}/tuxbox/config/${CAMNAME}/Sample.configs 2>/dev/null || true
}

do_rmwork () {
	:
}
