open Core_kernel
open Async
open Async_kernel

let () = Callback.register "hello" (fun name -> "Hello " ^ name)
let prover = ref None

let () =
  Callback.register "compile" (fun () ->
      Thread_safe.block_on_async_exn (fun () ->
          let%map () = after (Time_ns.Span.of_sec 1.) in
          print_endline "compiled";
          prover :=
            Some
              (fun input ->
                print_endline ("proving with input " ^ input);
                let%map () = after (Time_ns.Span.of_sec 1.) in
                "proof")))

let () =
  Callback.register "prove" (fun input ->
      let proof =
        Thread_safe.block_on_async_exn (fun () ->
            match !prover with
            | None -> failwith "not compiled"
            | Some p -> p input)
      in
      proof)
