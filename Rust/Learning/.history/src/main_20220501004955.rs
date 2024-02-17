mod test;
mod basics;
pub use basics::variables::adder; // put * instead of 'adder to use all functions

fn main() {
    test::hello();
    adder();
}
