{
  "targets": [{
    "target_name": "system_idle_time",
    "sources": [
      "src/module.cc"
    ],
    "include_dirs": [
      "<!(node -e \"require('nan')\")"
    ],
    "conditions": [
      ['OS=="mac"', {
        "defines": [
          "OS=1"
        ],
        "sources": [
          "src/mac/idle.cc"
        ],
        "xcode_settings": {
          "OTHER_CPLUSPLUSFLAGS": ["-std=c++11", "-stdlib=libc++", "-mmacosx-version-min=10.7"],
          "OTHER_LDFLAGS": ["-framework CoreFoundation -framework IOKit"]
        }
      }],
      ['OS=="win"', {
        "defines": [
          "OS=2"
        ],
        "sources": [
          "src/win/idle.cc"
        ],
        "msvs_settings": {
          "VCLinkerTool": {
            # Don't print a linker warning when no imports from either .exe are used.
            "AdditionalOptions": ["/ignore:4199"],
          },
        }
     }],
     ['OS=="linux"', {
       "defines": [
        "OS=3"
      ],
      'variables': {
	'pkg-config': 'pkg-config'
      },
      "sources": [
        "src/linux/idle.cc"
      ],
      'direct_dependent_settings': {
        'cflags': [
          '<!@(<(pkg-config) --cflags x11 xext xscrnsaver)',
        ],
      },
      'link_settings': {
        'ldflags': [
          '<!@(<(pkg-config) --libs-only-other --libs-only-L x11 xext xscrnsaver)',
        ],
        'libraries': [
          '<!@(<(pkg-config) --libs-only-l x11 xext xscrnsaver)',
        ],
      },
     }]
    ]
  }]
}
