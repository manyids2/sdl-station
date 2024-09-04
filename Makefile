sync-build:
	rsync -av \
		--exclude=".git" \
		--exclude=".cache" \
		--exclude="build" \
		--delete \
		./ \
		~/jj/anbernic/knulli-all/gutted-dist/output/h700/build/sdl-station/
