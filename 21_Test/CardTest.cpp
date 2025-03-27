#include "pch.h"
#include "..\21_Game\Card.cpp"
using namespace std;

TEST(CardTest, CardSimpleCreation) {
    Card* card = new Card();
    ASSERT_NE(card, nullptr);
    delete card;
}