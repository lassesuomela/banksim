<template>
  <v-data-table
    :headers="headers"
    dark
    :items="Accounts"
    sort-by="id"
    class="elevation-1 blue-grey darken-3"
  >
    <template v-slot:top>
      <v-toolbar
        rounded="2"
        class="cyan darken-1"
      >
        <v-toolbar-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
        Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
       <v-btn rounded small color="success">
       <v-icon left> mdi-account-plus
       </v-icon>
         Add
       </v-btn>

        
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
    </template>
  </v-data-table>
</template>

<script>
  import axios from "../axios"
  export default {
    data: () => ({
      dialog: false,
      dialogDelete: false,
      Accounts: [],
      headers: [
        { text: 'Name', align: 'start', sortable: false, value: 'name', },
        { text: 'Account ID', value: 'id' },
        { text: 'Balance €', value: 'balance' },
        { text: 'Actions', value: 'actions', sortable: false },
      ],
      defaultItem: { name: '', id: 0, balance: 0, },
    }),   
    created () {
      this.initialize()
    },
    methods: {
      initialize () {
        axios.get("/api/account").then((response) => {
          for(let i=0;i<response.data.length;i++){
            this.Accounts.push({name:response.data[i].name,id:response.data[i].account_ID,balance:response.data[i].balance});
          }
        });
      },
      deleteItem(item){
        axios.delete("/api/account",{id:Number(item.id)}).then((response) => {

        });
      }
    },
  }
</script>