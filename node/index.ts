import ffi from "ffi-napi";

const lib = ffi.Library("../ocaml/_build/default/lib", {
  init: ["void", []],
  hello: ["string", ["string"]],
  compile: ["void", []],
  prove: ["string", ["string"]],
});

lib.init();

console.log(lib.hello("name"));

lib.compile();
console.log("proof: ", lib.prove("input"));
