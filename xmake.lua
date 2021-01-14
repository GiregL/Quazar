-- 
--  Quazar Game Engine
--
--  Made by Lezenn
--

add_repositories("xmake-repo")

set_project("Quazar")
set_version("0.0.1")

set_languages("cxx17")

--
--  Core library
--
target("Core")
    set_kind("static")
    
    add_includedirs("include/Core")
    add_headerfiles("include/Core/**.hpp", "include/Core/**.inl")
    add_files("src/Core/**.cpp")
    
--
--  Graphics Library
--
target("Graphics")
    set_kind("static")
    
    add_deps("Core")
    
    add_includedirs("include/Graphics")
    add_headerfiles("include/Graphics/**.hpp", "include/Graphics/**.inl")
    add_files("src/Graphics/**.cpp")

--
--  Engine testing implementation
--
target("Testing")
    set_kind("binary")
    
    add_deps("Core", "Graphics")
    
    add_includedirs("include/Testing")
    add_headerfiles("include/Testing/**.hpp", "include/Testing/**.inl")
    add_files("src/Testing/**.cpp")

target_end()
