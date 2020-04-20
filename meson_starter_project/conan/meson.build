# Run Conan dependency installation as external command

conan = find_program('conan')
message('Running Conan dependency installation...')
# conan_out = run_command(conan, 'install', '--build=missing', '-if', '$MESON_BUILD_ROOT', '$MESON_SOURCE_ROOT/conan', check: true)

# Workaround for Meson not substituting $MESON_BUILD_ROOT and $MESON_SOURCE_ROOT in direct call of conan.
env = find_program('env')
conan_out = run_command(env, 'sh', '-c',
	'conan install --build=missing -if $MESON_BUILD_ROOT $MESON_SOURCE_ROOT/conan', check: true)

message(conan_out.stdout())
