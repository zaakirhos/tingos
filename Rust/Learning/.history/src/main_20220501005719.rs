mod test;
mod basics;
pub use basics::primitives; // put specific name instead of '*' to use all functions

fn main() {
    test::hello();
    primitive();
}
