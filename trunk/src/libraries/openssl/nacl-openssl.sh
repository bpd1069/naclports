#!/bin/bash
# Copyright (c) 2012 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

source pkg_info
source ../../build_tools/common.sh

CustomConfigureStep() {
  Banner "Configuring ${PACKAGE_NAME}"
  local EXTRA_ARGS=""
  if [ "${NACL_GLIBC}" != "1" ] ; then
    local GLIBC_COMPAT=${NACLPORTS_INCLUDE}/glibc-compat
    if [ ! -f ${GLIBC_COMPAT}/netdb.h ]; then
      echo "Please install glibc-compat first"
      exit 1
    fi
    EXTRA_ARGS+=" no-dso -DOPENSSL_NO_SOCK=1 -I${GLIBC_COMPAT}"
  fi

  ChangeDir ${NACL_PACKAGES_REPOSITORY}/${PACKAGE_NAME}
  MACHINE=i686 CC=${NACLCC} AR=${NACLAR} RANLIB=${NACLRANLIB} ./config \
     --prefix=${NACLPORTS_PREFIX} no-asm no-hw no-krb5 ${EXTRA_ARGS} -D_GNU_SOURCE
}

CustomHackStepForNewlib() {
  # These two makefiles build binaries which we do not care about,
  # and they depend on -ldl, so cannot be built with newlib.
  echo "all clean install: " > apps/Makefile
  echo "all clean install: " > test/Makefile
}

CustomBuildStep() {
  make clean
  make build_libs
}

CustomPackageInstall() {
  DefaultPreInstallStep
  DefaultDownloadStep
  DefaultExtractStep
  DefaultPatchStep
  CustomConfigureStep
  if [ "${NACL_GLIBC}" != "1" ]; then
    CustomHackStepForNewlib
  fi
  CustomBuildStep
  DefaultInstallStep
}

CustomPackageInstall
exit 0
