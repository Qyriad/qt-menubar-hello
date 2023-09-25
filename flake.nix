{
  inputs = {
    nixpkgs.url = "nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        inherit (builtins) path attrValues;

        menubar-qt5 = pkgs.stdenv.mkDerivation {
          name = "menubar";

          src = path {
            name = "menubar-src";
            path = ./.;
          };

          nativeBuildInputs = attrValues {
            inherit (pkgs)
              meson
              ninja
              pkg-config
            ;
            inherit (pkgs.qt5)
              qmake
              wrapQtAppsHook
            ;
          };

          buildInputs = attrValues {
            inherit (pkgs.qt5)
              qtbase
              qtwayland
              qttools
            ;
          };

          installPhase = ''
            mkdir -p $out/bin
            cp ./compile_commands.json $out/
            cp ./menubar $out/bin/
          '';

        };

        menubar-qt6 = pkgs.stdenv.mkDerivation {
          name = "menubar";

          src = path {
            name = "menubar-src";
            path = ./.;
          };

          nativeBuildInputs = attrValues {
            inherit (pkgs)
              meson
              ninja
              pkg-config
            ;
            inherit (pkgs.qt6)
              qmake
              wrapQtAppsHook
            ;
          };

          buildInputs = attrValues {
            inherit (pkgs.qt6)
              qtbase
              qtwayland
              qttools
            ;
          };

          mesonFlags = [ "-Dqt_version=qt6" ];

          installPhase = ''
            mkdir -p $out/bin
            cp ./compile_commands.json $out/
            cp ./menubar $out/bin/
          '';

        };
      in {

        packages = {
          default = menubar-qt5;
          inherit menubar-qt5 menubar-qt6;
        };

        devShells = {
          default = pkgs.mkShell {
            inputsFrom = [ menubar-qt5 ];
          };

          menubar-qt5 = pkgs.mkShell {
            inputsFrom = [ menubar-qt5 ];
          };

          menubar-qt6 = pkgs.mkShell {
            inputsFrom = [ menubar-qt6 ];
          };

        };

      }
    ) # eachDefaultSystem
  ; # outputs
}
