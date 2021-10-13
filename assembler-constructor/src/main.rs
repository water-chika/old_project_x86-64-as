fn main() {
    let doc = roxmltree::Document::parse("<instruction_set></instruction_set>").unwrap();
    for node in doc.descendants() {
        if node.is_element() {
            println!("{:?} at {}", node.tag_name(), doc.text_pos_at(node.range().start));
        }
    }
}
