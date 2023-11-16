import tkinter as tk

class TicketBookingApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Flight Ticket Booking System")
        self.root.geometry("600x600")  # Set the window size
        self.root.configure(bg="black")  # Set the background color of the root window to black
        self.queue = []
        self.max_seats = 10

        # Labels
        labels = ["Name", "Age", "Mobile Number", "Source", "Destination", "Priority", "Number of Tickets"]
        self.entry_widgets = {}

        for label_text in labels:
            label = tk.Label(root, text=label_text, bg="black", fg="white")
            label.pack()
            entry = tk.Entry(root)
            entry.pack()
            self.entry_widgets[label_text] = entry

        # Priority Menu
        self.priority_label = tk.Label(root, text="Priority:", bg="black", fg="white")
        self.priority_label.pack()

        self.priority_var = tk.StringVar()
        self.priority_var.set("General")
        self.priority_menu = tk.OptionMenu(root, self.priority_var, "Senior", "Army", "Student", "General")
        self.priority_menu.config(bg="black", fg="white")
        self.priority_menu.pack()

        # Number of Tickets Menu
        self.tickets_label = tk.Label(root, text="Number of Tickets:", bg="black", fg="white")
        self.tickets_label.pack()

        self.tickets_var = tk.IntVar()
        self.tickets_var.set(1)
        self.tickets_entry = tk.OptionMenu(root, self.tickets_var, 1, 2, 3, 4, 5)
        self.tickets_entry.config(bg="black", fg="white")
        self.tickets_entry.pack()

        # Buttons
        self.add_button = tk.Button(root, text="Add Customer", command=self.add_customer, bg="black", fg="white")
        self.add_button.pack()

        self.book_button = tk.Button(root, text="Book Ticket", command=self.book_ticket, bg="black", fg="white")
        self.book_button.pack()

        # Messages
        self.message_label = tk.Label(root, text="", bg="black", fg="white")
        self.message_label.pack()

        self.seats_label = tk.Label(root, text="Seats left: 10", fg="red", bg="black")
        self.seats_label.pack()

        # Display selected priority
        self.selected_priority_label = tk.Label(root, text="Selected Priority: General", bg="black", fg="white")
        self.selected_priority_label.pack()

    def add_customer(self):
        name = self.entry_widgets["Name"].get()
        age = self.entry_widgets["Age"].get()
        mobile = self.entry_widgets["Mobile Number"].get()
        source = self.entry_widgets["Source"].get()
        destination = self.entry_widgets["Destination"].get()
        priority = self.priority_var.get()
        num_tickets = self.tickets_var.get()

        if name and age and mobile and source and destination and num_tickets > 0:
            if len(self.queue) + num_tickets > self.max_seats:
                self.message_label.config(text="Not enough seats available.")
            else:
                if priority == "Senior":
                    priority_value = 1
                elif priority == "Army":
                    priority_value = 2
                elif priority == "Student":
                    priority_value = 3
                else:
                    priority_value = 4

                for _ in range(num_tickets):
                    customer = {
                        'name': name,
                        'age': age,
                        'mobile': mobile,
                        'source': source,
                        'destination': destination,
                        'priority': priority_value
                    }
                    self.queue.append(customer)
                self.message_label.config(text=f"{num_tickets} ticket(s) for {name} added to the queue.")
                self.update_seats_label()
        else:
            self.message_label.config(text="Please fill in all fields and select the number of tickets.")

    def book_ticket(self):
        if not self.queue:
            self.message_label.config(text="No customers in the queue.")
        else:
            # Sort the queue based on priority (lower value means higher priority)
            self.queue.sort(key=lambda x: x['priority'])
            if len(self.queue) > self.max_seats:
                self.queue = self.queue[:self.max_seats]  # Truncate the queue to the maximum limit
            booked_customers = [f"Name: {customer['name']}, Age: {customer['age']}, Source: {customer['source']}, Destination: {customer['destination']}, Priority: {customer['priority']}" for customer in self.queue]
            self.message_label.config(text="Booked Tickets:\n" + "\n\n".join(booked_customers))
            self.update_seats_label()

            # Display selected priority
            selected_priority = self.priority_var.get()
            self.selected_priority_label.config(text=f"Selected Priority: {selected_priority}")

    def update_seats_label(self):
        seats_left = self.max_seats - len(self.queue)
        self.seats_label.config(text=f"Seats left: {seats_left}", fg="red")

if __name__ == '__main__':
    root = tk.Tk()
    app = TicketBookingApp(root)
    root.mainloop()
