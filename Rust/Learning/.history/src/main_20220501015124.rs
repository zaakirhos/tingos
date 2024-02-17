mod test;
mod basics;
pub use basics::*; // put specific name instead of '*' to use all functions

fn main() {
    test::hello();
    // types::primitive();
    // types::tuple();
    types::array();
    types::structure();
    types::enumeration()
}
