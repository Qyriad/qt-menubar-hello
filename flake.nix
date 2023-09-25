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

        menubar = pkgs.stdenv.mkDerivation {
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
            inherit (pkgs.libsForQt5)
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
      in {
        packages.default = menubar;
        devShells.default = pkgs.mkShell {
          inputsFrom = [ menubar ];
        };
      }
    ) # eachDefaultSystem
  ; # outputs
}
