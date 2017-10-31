cxx_binary(
    name = 'counter',
    header_namespace = 'counter',
    headers = subdir_glob([
        ('app/include', '**/*.h'),
    ]),
    srcs = glob([
        'app/src/**/*.c',
    ]),
    deps = [
        '//stack:stack',
    ],
    compiler_flags = [
        '-g',
    ],
)
