using System;
using JokesLib;


namespace Jokes
{
    class Program
    {
        static void Main(string[] args)
        {
            Joke horse = new Joke
            {
                Question = "A horse goes into a bar and the bartender says why the long face?",
                Answer = "The horse says, that's racist!",
                jokeIndex = 3
            };

            System.Console.WriteLine(horse.Question);
            // System not needed because we indicated that we are using that namespace
            Console.WriteLine(horse.Answer);
            Console.WriteLine("The Joke index is ${horse.jokeIndex}");
        }
    }
}
