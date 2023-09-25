project(
  'menubar',
  'cpp',
  default_options: [
    'default_library=static',
    'cpp_std=c++20',
    'warning_level=2',
    'buildtype=debugoptimized',
  ],
  version: '0.0.1',
)

qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Gui', 'Widgets'])
inc = include_directories('src')

headers = [
  'src/mainwindow.hpp',
]

sources = [
  'src/mainwindow.cpp',
  'src/main.cpp',
]

moc_files = qt5.compile_moc(headers: headers, dependencies: qt5_dep)

executable('menubar', sources, moc_files, dependencies: qt5_dep)
