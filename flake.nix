{
	description = "Effie";
	inputs = {
		nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
		flake-utils.url = "github:numtide/flake-utils";
	};
	outputs = {self, nixpkgs, flake-utils}:
	flake-utils.lib.eachDefaultSystem(system:
	let
		pkgs = nixpkgs.legacyPackages.${system};
	in {
		devShell = pkgs.mkShell {
			packages = with pkgs; [
				clang
				cmake
				gnumake
				pkg-config
				sdl3
			];
		};
	});
}
