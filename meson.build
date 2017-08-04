
project(
  'freeserf', 'cpp',
  version: '0.2',
  default_options: ['cpp_std=c++11'])

sdl2 = dependency('sdl2', required: true)
sdl2_mixer = dependency('SDL2_mixer', required: false)
libxmp = dependency('libxmp', required: false)

gtest = subproject('gtest')
gtest_dep = gtest.get_variable('gtest_with_main_dep')

game_src = [
  'src/building.cc',
  'src/debug.cc',
  'src/flag.cc',
  'src/game.cc',
  'src/inventory.cc',
  'src/log.cc',
  'src/map.cc',
  'src/map-generator.cc',
  'src/player.cc',
  'src/random.cc',
  'src/savegame.cc',
  'src/serf.cc',
]

other_src = [
  'src/data.cc',
  'src/pathfinder.cc',
  'src/gfx.cc',
  'src/viewport.cc',
  'src/minimap.cc',
  'src/interface.cc',
  'src/gui.cc',
  'src/popup.cc',
  'src/game-init.cc',
  'src/notification.cc',
  'src/panel.cc',
  'src/video-sdl.cc',
  'src/video.cc',
  'src/audio.cc',
  'src/version.cc',
  'src/data-source-dos.cc',
  'src/tpwm.cc',
  'src/event_loop.cc',
  'src/event_loop-sdl.cc',
  'src/sfx2wav.cc',
  'src/xmi2mid.cc',
  'src/data-source.cc',
  'src/text-input.cc',
  'src/data-source-amiga.cc',
  'src/list.cc',
  'src/mission.cc',
  'src/game-manager.cc',
]

test_game_src = [
  'tests/test_map_geometry.cc',
  'tests/test_map.cc',
  'tests/test_save_game.cc',
]

version_vcs = vcs_tag(
  input: 'src/version-vcs.h.in',
  output: 'version-vcs.h',
  command: ['git', 'describe', '--always', '--tags', '--dirty'])

freeserf_dependencies = [sdl2]
audio_src = []
if sdl2_mixer.found()
  freeserf_dependencies += [sdl2_mixer]
  audio_src += ['src/audio-sdlmixer.cc']
else
  audio_src += ['src/audio-dummy.cc']
endif

executable(
  'freeserf',
  sources: ['src/freeserf.cc'] + game_src + audio_src + other_src,
  dependencies: freeserf_dependencies)

test_game = executable(
  'test_game',
  sources: test_game_src + game_src,
  dependencies: gtest_dep)

test('test game', test_game, env: ['srcdir=' + meson.current_source_dir()])
