fn main() {
    let args: Vec<_> = std::env::args().collect();
    if args.len() != 2 {
        println!("Usage:\n\tcargo run input.xml");
        std::process::exit(1);
    }
    let text = std::fs::read_to_string(&args[1]).unwrap();
    let doc = roxmltree::Document::parse(&text).unwrap();
    let instruction_set = doc.root().first_child().unwrap();
    let instruction_items = instruction_set.descendants().filter(|n| n.tag_name().name() == "instruction_item");

    for instruction_item in instruction_items {
        let instructions = instruction_item.descendants().filter(|n| n.tag_name().name() == "instruction");
        for instruction in instructions {
            let mnemonic = instruction.children().filter(|n| n.tag_name().name() == "mnemonic").nth(0).unwrap();
            println!("{}", mnemonic.text().unwrap());
        }
    }
}
