################################################################################
#
# sdl-station
#
################################################################################
# SDLSTATION_SITE = /sources/sdl-station
SDLSTATION_SITE_METHOD = local
# SDLSTATION_LICENSE = MIT
# SDLSTATION_GIT_SUBMODULES = YES
SDLSTATION_DEPENDENCIES = sdl2 libfreeimage freetype alsa-lib
# install in staging for debugging (gdb)
# SDLSTATION_INSTALL_STAGING = YES
SDLSTATION_OVERRIDE_SRCDIR = /sources/sdl-station

SDLSTATION_CONF_OPTS += \
    -DCMAKE_CXX_FLAGS=-D$(call UPPERCASE,$(BATOCERA_SYSTEM_ARCH))

ifeq ($(BR2_PACKAGE_HAS_LIBMALI),y)
SDLSTATION_DEPENDENCIES += libmali
SDLSTATION_CONF_OPTS += -DCMAKE_EXE_LINKER_FLAGS=-lmali
SDLSTATION_CONF_OPTS += -DCMAKE_SHARED_LINKER_FLAGS=-lmali
endif

ifeq ($(BR2_PACKAGE_HAS_LIBGL),y)
SDLSTATION_CONF_OPTS += -DGL=ON
else
ifeq ($(BR2_PACKAGE_HAS_LIBGLES),y)
SDLSTATION_CONF_OPTS += -DGLES2=ON
endif
endif

SDLSTATION_CONF_OPTS += -DBATOCERA=ON

SDLSTATION_SOURCE_PATH = \
    $(BR2_EXTERNAL_BATOCERA_PATH)/package/sdl-station

define SDLSTATION_RESOURCES
	# hooks
	mkdir -p $(TARGET_DIR)/usr/share/sdl-station
endef

### S31emulationstation
# default for most of architectures
SDLSTATION_PREFIX = SDL_NOMOUSE=1
SDLSTATION_CMD = sdl-station-standalone
SDLSTATION_ARGS = --no-splash $${EXTRA_OPTS}
SDLSTATION_POSTFIX = \&

# disabling cec. causing perf issue on init/deinit
#ifeq ($(BR2_PACKAGE_BATOCERA_TARGET_RK3128),y)
SDLSTATION_CONF_OPTS += -DCEC=OFF
#else
#SDLSTATION_CONF_OPTS += -DCEC=ON
#endif

define SDLSTATION_BOOT
	$(INSTALL) -D -m 0755 $(SDLSTATION_SOURCE_PATH)/sdl-station-standalone \
	    $(TARGET_DIR)/usr/bin/sdl-station-standalone
	sed -i -e 's;%SDLSTATION_PREFIX%;${SDLSTATION_PREFIX};g' \
		-e 's;%SDLSTATION_CMD%;${SDLSTATION_CMD};g' \
		-e 's;%SDLSTATION_ARGS%;${SDLSTATION_ARGS};g' \
		-e 's;%SDLSTATION_POSTFIX%;${SDLSTATION_POSTFIX};g' \
		$(TARGET_DIR)/usr/bin/sdl-station-standalone
endef

SDLSTATION_POST_INSTALL_TARGET_HOOKS += SDLSTATION_RESOURCES
SDLSTATION_POST_INSTALL_TARGET_HOOKS += SDLSTATION_BOOT

$(eval $(cmake-package))
