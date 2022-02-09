// Copyright 2022 Grayson Hay.
// SPDX-License-Identifier: MIT
use std::env;

fn main() {
	let crate_dir = env::var("CARGO_MANIFEST_DIR").unwrap();

	cbindgen::generate(crate_dir).expect("Unable to generate bindings!").write_to_file("includes/chyron.h");
}
