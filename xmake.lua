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
    
    add_includedirs("Core/include")
    add_headerfiles("Core/include/**.hpp", "Core/include/**.inl")
    add_files("Core/src/**.cpp")
    
--
--  Graphics Library
--
target("Graphics")
    set_kind("static")
    
    add_deps("Core")
    
    add_includedirs("Graphics/include")
    add_headerfiles("Graphics/include/**.hpp", "Graphics/include/**.inl")
    add_files("Graphics/src/**.cpp")

--
--  Engine testing implementation
--
target("Testing")
    set_kind("binary")
    
    add_deps("Core", "Graphics")
    
    add_includedirs("Testing/include")
    add_headerfiles("Testing/include/**.hpp", "Testing/include/**.inl")
    add_files("Testing/src/**.cpp")

target_end()
