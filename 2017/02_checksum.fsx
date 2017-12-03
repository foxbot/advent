namespace Checksum
module Checksum =
    open System.IO

    // splits a tab-separated string into parts
    let tsvStr (str:string): string[] =
        str.Split([|' '; '\t'|])

    // safely parse a string to an integer (used for debugging, mostly)
    let safeParse (str:string): int =
        match System.Int32.TryParse str with
        | (true, int) -> int
        | (false, _) -> -1

    // map a given row of strings to a row of ints
    let strToInt (str:string[]): int list =
        Array.map safeParse str |> Array.toList

    // find the difference between the max and min of the row
    let rowDiff (row: int list): int =
        let high = List.max row
        let low = List.min row
        high - low

    // find the divisible values in the row, and then divide
    let rowDiv (row: int list): int =
        let r = List.filter (fun x -> List.exists (fun y -> x <> y && (x % y = 0 || y % x = 0)) row) row
        List.max r / List.min r

    let data = File.ReadAllText "02_checksum.in"
    // split the input into rows, trim them into rows/cols, and convert the cols to ints
    let rows = Array.map (tsvStr >> strToInt) (data.Split '\n')
    let partOne = rows |> Array.sumBy rowDiff
    let partTwo = rows |> Array.sumBy rowDiv

    let checksum = match fsi.CommandLineArgs.[1] |> int with
                   | 1 -> partOne
                   | 2 -> partTwo
                   | _ -> -1

    printfn "%A" checksum