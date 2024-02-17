mod test;
mod basics;
pub use basics::variables::*; // put specific name instead of '*' to use all functions

fn main() {
    test::hello();
    primitives();
}
