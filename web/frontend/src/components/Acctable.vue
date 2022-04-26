<template>
  <v-data-table
    :headers="headers"
    dark
    :items="Accounts"
    :items-per-page="5"
    sort-by="id"
    class="elevation-1 blue-grey darken-3"
  >
    <template v-slot:top>
      <v-toolbar rounded="" class="cyan darken-1">
        <v-toolbar-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3">
          Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
        <v-dialog v-model="dialogAddUser" max-width="500px">
          <v-card color="blue-grey darken-3">
            <v-form @submit.prevent="addUserToAccount" id="adduseraccount-form">
            <v-toolbar rounded="" class="cyan darken-1">
              <v-icon>mdi-person</v-icon>
              <v-card-title
                class="font-weight-bold text-h5 blue-grey--text text--darken-3"
              >
                <span class="text-h5">Add user to account</span>
              </v-card-title>
            </v-toolbar>
            <br />
            <v-card-text>
              <v-container>
                <v-row>
                  <v-col>
                    <v-text-field
                      v-model="addUserEmail"
                      dark
                      color="cyan darken-1"
                      type="email"
                      label="Email"
                      prepend-icon="mdi-account-plus"
                    ></v-text-field>
                  </v-col>
                </v-row>
              </v-container>
            </v-card-text>
            <v-card-actions>
              <v-spacer></v-spacer>
              <v-btn color="cyan darken-1" text @click="dialogAddUser = false">
                Close
              </v-btn>
              <v-btn type="submit" form="adduseraccount-form" color="cyan darken-1" text @click="dialogAddUser = false">
                Add
              </v-btn>
            </v-card-actions>
            </v-form>
          </v-card>
        </v-dialog>
        <v-dialog v-model="dialogDelete" persistent max-width="600px">
          <v-card color="blue-grey darken-3">
            <v-form @submit.prevent="disconnectUsers" id="deleteuseremail-form">
              <v-toolbar rounded="" class="cyan darken-1">
                <v-card-title
                  class="
                    font-weight-bold
                    text-h5
                    blue-grey--text
                    text--darken-3">
                  <span class="text-h5">Remove user from account</span>
                </v-card-title>
              </v-toolbar>
              <v-card-text>
                <v-container>
                  <v-row>
                    <v-col>
                      <v-select
                        v-model="deleteUserEmail"
                        dark
                        color="cyan darken-1"
                        :items="connectedUsers"
                        item-value="id"
                        item-text="email"
                        label="User email"
                        prepend-icon="mdi-email"
                      ></v-select>
                    </v-col>
                  </v-row>
                </v-container>
              </v-card-text>
              <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn color="cyan darken-1" text @click="dialogDelete = false">
                  Close
                </v-btn>
                <v-btn
                  type="submit"
                  form="deleteuseremail-form"
                  color="cyan darken-1"
                  text
                  @click="dialogDelete = false">
                  Delete
                </v-btn>
              </v-card-actions>
            </v-form>
          </v-card>
        </v-dialog>

        <accadd />
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small class="mr-2" @click="editItem(item)">mdi-account-plus</v-icon>
      <v-icon small class="mr-2" @click="getConnectedUsers(item)">mdi-account-minus</v-icon>
      <v-icon small @click="deleteAccount(item)">mdi-delete</v-icon>
    </template>
  </v-data-table>
</template>

<script>
import axios from "../axios";
import accadd from "./accadd.vue";
export default {
  components: { accadd },
  data: () => ({
    dialogAddUser: false,
    dialogDelete: false,
    addUserEmail: "",
    deleteUserEmail: "",
    itemdata: null,
    userAccountTrigger: false,
    resError: "",
    selectedAccount: null,
    selectedUser: null,
    connectedUsers: [],
    Accounts: [],
    headers: [
      { text: "Name", align: "start", sortable: false, value: "name" },
      { text: "Account ID", value: "id" },
      { text: "Balance €", value: "balance" },
      { text: "Actions", value: "actions", sortable: false },
    ],
    defaultItem: { name: "", id: 0, balance: 0 },
  }),
  created() {
    this.initialize();
  },
  methods: {
    editItem(item) {
      this.dialogAddUser = true;
      this.itemdata = item;
    },
    getConnectedUsers(item) {
      this.connectedUsers = [];
      this.dialogDelete = true;
      this.selectedAccount = item.id;
      axios.get("/api/account/"+item.id+"/users").then((response) => {
        if(response.data.status === "success"){
          for(let i=0;i<response.data.message.length;i++){
            this.connectedUsers.push({
              id: response.data.message[i].user_ID,
              email: response.data.message[i].email
            });
          }
        }
      });
    },
    disconnectUsers(item){
      for(let i=0;i<this.connectedUsers.length;i++){
        if(this.deleteUserEmail === this.connectedUsers[i].id){
          this.selectedUser = i;
        }
      }
      axios.delete("/api/account/user", {data: {account: this.selectedAccount, user: this.connectedUsers[this.selectedUser].id} }).then((response) => {
        if(response.data.status === "success"){
          this.$router.go();
        }
      });
    },
    initialize() {
      axios.get("/api/account").then((response) => {
        for (let i = 0; i < response.data.length; i++) {
          this.Accounts.push({
            name: response.data[i].name,
            id: response.data[i].account_ID,
            balance: response.data[i].balance,
          });
        }
      });
    },
    addUserToAccount(){
      if(this.itemdata){
        axios.post("/api/account/adduser",{email:this.addUserEmail,id:this.itemdata.id}).then((response) => {
          if(response.data.status === "success"){
            this.$router.go();
          }
      });
      }
    },
    deleteAccount(item) {
      axios.delete("/api/account", { data: { id: item.id } }).then((response) => {
          if (response.data.status === "success") {
            this.$router.go();
          }
        });
    },
  },
};
</script>