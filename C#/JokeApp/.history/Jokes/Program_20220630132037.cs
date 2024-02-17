using System;
using JokesLib;


namespace Jokes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("");
            Joke horse = new Joke
            {
                Question = "What do you call a horse with no legs?",
                Answer = "A horse with no legs"
            };
        }
    }
}
