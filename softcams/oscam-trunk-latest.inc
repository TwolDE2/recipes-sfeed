SRCREV = "${AUTOREV}"
CAMNAME = "oscam-trunk"
SUMMARY_${PN} = "OSCam-trunk ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest trunk"

#PR = "r0"

RPROVIDES_${PN} += "enigma2-plugin-softcams-oscam-openvix"
RREPLACES_${PN} += "enigma2-plugin-softcams-oscam-openvix"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-oscam-openvix"

SRC_URI += "svn://svn.streamboard.tv/oscam;protocol=https;module=trunk;scmdata=keep"
