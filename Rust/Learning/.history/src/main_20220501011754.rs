mod test;
mod basics;
pub use basics::types::*; // put specific name instead of '*' to use all functions

fn main() {
    test::hello();
    types::primitive();
    types::tuple();
}
