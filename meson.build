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

qt_version = get_option('qt_version')

if qt_version == 'qt5'
  qt = import('qt5')
  qt_dep = dependency('qt5', modules: ['Core', 'Gui', 'Widgets'])
elif qt_version == 'qt6'
  qt = import('qt6')
  qt_dep = dependency('qt6', modules: ['Core', 'Gui', 'Widgets'])
endif

headers = [
  'src/mainwindow.hpp',
]

sources = [
  'src/mainwindow.cpp',
  'src/main.cpp',
]

moc_files = qt.compile_moc(headers: headers, dependencies: qt_dep)

executable('menubar', sources, moc_files, dependencies: qt_dep)
