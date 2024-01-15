#include "square.h"

//Constructors
Square::Square(SquareType type, std::string owner) : type_(type), owner_(owner), has_house_(false), has_hotel_(false) {}

Square::Square(SquareType type) : type_(type), owner_(""), has_house_(false), has_hotel_(false) {}

//Destructor
Square::~Square() {}

//Getter functions
SquareType Square::GetType() const { return type_; }

std::string Square::GetOwner() const { return owner_; }

bool Square::HasHouse() const { return has_house_; }

bool Square::HasHotel() const { return has_hotel_; }

//Setter functions
void Square::SetOwner(const std::string& owner) { owner_ = owner; }

void Square::BuildHouse() {
	if (has_house_) {
		std::cout << "There is already a house, you can't build here. \n";
	}	else {
		has_house_ = true;
	}
		

}

void Square::BuildHotel() {
	if (has_hotel_) {
		std::cout << "There is already a hotel, you can't build here. \n";
	}	else {
		has_hotel_ = true;
	}
}

void Square::RemoveHouse() {
	if (has_house_) {
		has_house_ = false;
	} else {
		std::cout << "There isn't a house to remove. \n";
	}
}

void Square::RemoveHotel() {
	if (has_hotel_) {
		has_hotel_ = false;
	} else {
		std::cout << "There isn't a house to remove. \n";
	}
}

//Check function
bool Square::IsOwned() const {
	return !owner_.empty();
}
