{
  "targets": [{
    "target_name": "addon",
    "sources": [
      "src/module.cc"
    ],
    "include_dirs": [
      "<!(iojs -e \"require('nan')\")"
    ],
    "conditions": [
      ['OS=="mac"', {
        "defines": [
          "OS=1"
        ],
        "sources": ["src/mac/idle.cc"],
        "xcode_settings": {
          "OTHER_CPLUSPLUSFLAGS": ["-std=c++11", "-stdlib=libc++", "-mmacosx-version-min=10.7"],
          "OTHER_LDFLAGS": ["-framework CoreFoundation -framework IOKit"]
        }
      }],
      ['OS=="win"', {
        "defines": [
          "OS=2"
        ],
        "sources": ["src/win/idle.cc"]
      }]
    ]
  }]
}
