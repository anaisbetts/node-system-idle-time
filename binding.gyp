{
  "targets": [{
    "target_name": "system-idle-time",
    "conditions": [
      ['OS=="mac"', {
        "sources": ["src/module.cc", "src/mac/idle.cc"],
        "xcode_settings": {
          "OTHER_CPLUSPLUSFLAGS": ["-std=c++11", "-stdlib=libc++", "-mmacosx-version-min=10.7"],
          "OTHER_LDFLAGS": ["-framework CoreFoundation -framework IOKit"]
        }
      }]
    ]
  }]
}
