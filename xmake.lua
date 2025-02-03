set_xmakever("2.2.2")

set_project("timer")
set_version("1.0.0")

includes("@builtin/xpack")

add_rules("mode.debug", "mode.release") -- debug mode and release mode
set_languages("c++14") -- set c++ standard

target("timer")
    set_kind("binary")
    add_files("src/*.cpp")
target_end()

xpack("timer")
    -- set formats
    set_formats("zip", "targz", "nsis")

    set_basename("timer-$(version)-$(plat)-$(arch)")

    set_description("A Timer tool")
    set_author("ACoderOrHacker")
    set_license("MIT")
    set_licensefile("LICENSE")
    set_title("Timer")

    add_targets("timer")
xpack_end()
