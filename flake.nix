{
  inputs = {
    nixpkgs = {
      url = "github:nixos/nixpkgs/nixos-unstable";
    };
    flake-utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs = { nixpkgs, flake-utils, ... }: flake-utils.lib.eachDefaultSystem (system:
    let
      pkgs = import nixpkgs {
        inherit system;
      };
    in rec {
      # packages.myapp = pkgs.stdenv.mkDerivation {
      #   name = "myapp";
      #   src = self;
      #   buildInputs = [ pkgs.cmake pkgs.gcc ]; // Adjust with required dependencies
      #   configurePhase = ''
      #     cmake . -DCMAKE_INSTALL_PREFIX=$out
      #   '';
      #   buildPhase = ''
      #     cmake --build .
      #   '';
      #   installPhase = ''
      #     cmake --install .
      #   '';
      # };
      #
      # defaultPackage = self.packages.myapp;

      devShell = pkgs.mkShell {
        buildInputs = with pkgs; [
            sourcekit-lsp
            opencv4
            cmake
            gdb
            clang-tools
            cppcheck
        ];

        shellHook = ''
            export LDFLAGS="-L${pkgs.opencv4}/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs"
        '';
      };
    }
  );
}


