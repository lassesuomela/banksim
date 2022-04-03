
<template>
<div class="dashboard">
 <app-sidebar/>
 <app-cards/>
   <v-row >
    <v-col cols="12" sm="8">
      <v-card class="blue-grey darken-3">
        <v-card-title class="cyan darken-1">
          <span class="font-weight-bold text-h5 blue-grey--text text--darken-3">Add card</span>
        </v-card-title>
      <v-col class="d-flex" >
        <v-select dark color="cyan darken-1" :items="accountlist" label="Account" prepend-icon="person" ></v-select>
      </v-col>
      <v-col class="d-flex" >
        <v-select dark color="cyan darken-1" :items="cardtype" label="Debit or Credit" prepend-icon="person" ></v-select>
      </v-col>
      <br>                    
      <div class="text-center ">
         <v-btn type="submit" rounded color="cyan darken-1" dark form="login-form">Add card</v-btn>
      </div>
      <br>
      </v-card>
    </v-col>
  </v-row>
</div>
</template>

<script>
import axios from "../axios"
export default {
    data(){
      return {
        accountlist: [],
        cardtype: ['Debit', 'Credit'],
      }
    },
    methods:{
      getAccounts(){
        axios.get("/api/account").then((response) => {
          for(var i=0;i<response.data.length;i++){
            this.accountlist.push(response.data[i].account_ID);
          }
        });
      },
      
    },
    mounted(){
      this.getAccounts();
    }
  }
    
</script>

<style scoped>
    .overlap-icon {
        position: absolute;
        top: -33px;
        text-align: center;
        padding-top: 12px;
    }

</style>
