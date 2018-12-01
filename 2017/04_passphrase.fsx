//namespace Passphrase
module Passphrase = 
    open System.IO

    let isValid (phrase:string[]) =
        let distinct = Array.distinct phrase
        Array.length distinct = Array.length phrase

    let data = File.ReadAllText "04_passphrase.in"

    let phrases = data.Split '\n' 
                  |> Array.toList 
                  |> List.map (fun (p:string) -> p.Split ' ')

    let partOne = 
        phrases |> List.filter isValid |> List.length

    let result = match fsi.CommandLineArgs.[1] |> int with
                 | 1 -> partOne
                 | _ -> -1

    printfn "%A" result