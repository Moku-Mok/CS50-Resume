-- Keep a log of any SQL queries you execute as you solve the mystery.

 July 28, 2023
 Humphrey Street.

SELECT * FROM crime_scene_reports
    WHERE month = 7 AND street = 'Humphrey Street';

--Duck theft mentioned in id 295, 10:15 am at a bakery. 3 interviewed witnesses, each mentions bakery in transcript.

--Get the interviews and people's names next.

SELECT * FROM interviews
    WHERE transcript LIKE '%bakery%';

-- Ruth, Eugene, Raymond, 3 Interviews about a bakery theft on the day of the crime.

-- Ruth mentions: Sometime within ten minutes of the theft, thief got into his car in the parking lot and left. Check security footage for car.
-- Eugene mentions: They reckognized thief, but dont remember name. Saw them withdrawing money at ATM on Leggett Street earlier in the morning.

-- Raymond mentions: Thief made a phonecall for less than a minute while leaving. Thief said they were planning to take the earliest flight out of fiftyville tomorrow.
--                   This would mean the 29. 7. Asked the other person on the phone to buy the ticket.


-- Check Security Logs of mentioned timeslot.
SELECT * FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND hour = 10 AND minute > 15 AND minute < 26;

-- 8 possible cars. Activity at the exit for each.
-- ID's 260-267.

--Check ATM Transaction on LEGGET STREET

SELECT * FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = 'Leggett Street';

-- ID's 246, 264, 266, 267, 269, 288, 313, 336
-- respectively withdrew money from an ATM on Leggett Street on that day.

-- Check for Phone calls lasting less than a minute around the incident time.

SELECT * FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60;

-- ID's 221, 224, 233, 251, 254, 255, 261, 279, 281, each made short calls on the day.

-- Try to match a person through License plate of cars that left bakery and phone numbers that fit the ID's above.

SELECT * FROM people
    WHERE license_plate IN
        (
            SELECT license_plate FROM bakery_security_logs
                WHERE month = 7 AND day = 28
                AND hour = 10 AND minute > 14 AND minute < 26
        )
    AND phone_number IN
        (
            SELECT caller FROM phone_calls
                WHERE month = 7 AND day = 28
                AND duration < 60
        );


--Crossreference who withdrew from the street with who left and had a phone call like described.

SELECT * FROM atm_transactions
    JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
    JOIN people ON bank_accounts.person_id = people.id

    WHERE atm_location = 'Leggett Street'
    AND month = 7 AND day = 28;

--Return: Bruce, Diana

--What is first flight out of town on 29.?

SELECT * FROM airports
    WHERE city = 'Fiftyville';

--Fiftyville Airport's ID is 8

SELECT * FROM flights
    WHERE origin_airport_id = 8
    AND month = 7 AND day = 29
    ORDER BY hour;

--Earliest flight is 36, leaving at 8 20 AM.
--Did it contain either Bruce or Diana?

SELECT * FROM flights
    JOIN passengers ON flights.id = passengers.flight_id

    WHERE flights.id = 36
    AND passport_number = 5773159633 OR passport_number = 3592750733;

--Bruce left on the earliest flight, Diana went on some round-trip, so I guess it's Bruce.
--Who did he call to get him the ticket?

SELECT * FROM people
    WHERE phone_number = '(375) 555-8161';

--The number we can check from an earlier query we made on the calls.
--He called Robin, who bought him the ticket, I assume. What does it MEAN when you don't have a passport?!

--And wait, where did Bruce fly to?
--destination airport id 4

SELECT * FROM airports
    WHERE id = 4;

--Homie went to New York City
--I got impatient and glanced over the lines earlier, looked at the wrong flight and initially chose boston......

--May I finally leave the SQL mines...This Set really gave me motivational issues!
