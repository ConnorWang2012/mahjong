// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: room_list_msg_protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "room_list_msg_protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* RoomItemMsgProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RoomItemMsgProtocol_reflection_ = NULL;
const ::google::protobuf::Descriptor* RoomListMsgProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RoomListMsgProtocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_room_5flist_5fmsg_5fprotocol_2eproto() {
  protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "room_list_msg_protocol.proto");
  GOOGLE_CHECK(file != NULL);
  RoomItemMsgProtocol_descriptor_ = file->message_type(0);
  static const int RoomItemMsgProtocol_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, room_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, room_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, sub_room_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, score_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, cost_score_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, min_score_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, base_score_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, cur_players_num_),
  };
  RoomItemMsgProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RoomItemMsgProtocol_descriptor_,
      RoomItemMsgProtocol::default_instance_,
      RoomItemMsgProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomItemMsgProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RoomItemMsgProtocol));
  RoomListMsgProtocol_descriptor_ = file->message_type(1);
  static const int RoomListMsgProtocol_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomListMsgProtocol, player_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomListMsgProtocol, room_items_),
  };
  RoomListMsgProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RoomListMsgProtocol_descriptor_,
      RoomListMsgProtocol::default_instance_,
      RoomListMsgProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomListMsgProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomListMsgProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RoomListMsgProtocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_room_5flist_5fmsg_5fprotocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RoomItemMsgProtocol_descriptor_, &RoomItemMsgProtocol::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RoomListMsgProtocol_descriptor_, &RoomListMsgProtocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_room_5flist_5fmsg_5fprotocol_2eproto() {
  delete RoomItemMsgProtocol::default_instance_;
  delete RoomItemMsgProtocol_reflection_;
  delete RoomListMsgProtocol::default_instance_;
  delete RoomListMsgProtocol_reflection_;
}

void protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034room_list_msg_protocol.proto\022\016gamer.pr"
    "otocol\"\270\001\n\023RoomItemMsgProtocol\022\017\n\007room_i"
    "d\030\001 \002(\r\022\021\n\troom_type\030\002 \001(\r\022\025\n\rsub_room_t"
    "ype\030\003 \001(\r\022\022\n\nscore_type\030\004 \001(\r\022\022\n\ncost_sc"
    "ore\030\005 \001(\r\022\021\n\tmin_score\030\006 \001(\r\022\022\n\nbase_sco"
    "re\030\007 \001(\r\022\027\n\017cur_players_num\030\010 \001(\r\"a\n\023Roo"
    "mListMsgProtocol\022\021\n\tplayer_id\030\001 \002(\r\0227\n\nr"
    "oom_items\030\002 \003(\0132#.gamer.protocol.RoomIte"
    "mMsgProtocol", 332);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "room_list_msg_protocol.proto", &protobuf_RegisterTypes);
  RoomItemMsgProtocol::default_instance_ = new RoomItemMsgProtocol();
  RoomListMsgProtocol::default_instance_ = new RoomListMsgProtocol();
  RoomItemMsgProtocol::default_instance_->InitAsDefaultInstance();
  RoomListMsgProtocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_room_5flist_5fmsg_5fprotocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_room_5flist_5fmsg_5fprotocol_2eproto {
  StaticDescriptorInitializer_room_5flist_5fmsg_5fprotocol_2eproto() {
    protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  }
} static_descriptor_initializer_room_5flist_5fmsg_5fprotocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RoomItemMsgProtocol::kRoomIdFieldNumber;
const int RoomItemMsgProtocol::kRoomTypeFieldNumber;
const int RoomItemMsgProtocol::kSubRoomTypeFieldNumber;
const int RoomItemMsgProtocol::kScoreTypeFieldNumber;
const int RoomItemMsgProtocol::kCostScoreFieldNumber;
const int RoomItemMsgProtocol::kMinScoreFieldNumber;
const int RoomItemMsgProtocol::kBaseScoreFieldNumber;
const int RoomItemMsgProtocol::kCurPlayersNumFieldNumber;
#endif  // !_MSC_VER

RoomItemMsgProtocol::RoomItemMsgProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.protocol.RoomItemMsgProtocol)
}

void RoomItemMsgProtocol::InitAsDefaultInstance() {
}

RoomItemMsgProtocol::RoomItemMsgProtocol(const RoomItemMsgProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.protocol.RoomItemMsgProtocol)
}

void RoomItemMsgProtocol::SharedCtor() {
  _cached_size_ = 0;
  room_id_ = 0u;
  room_type_ = 0u;
  sub_room_type_ = 0u;
  score_type_ = 0u;
  cost_score_ = 0u;
  min_score_ = 0u;
  base_score_ = 0u;
  cur_players_num_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RoomItemMsgProtocol::~RoomItemMsgProtocol() {
  // @@protoc_insertion_point(destructor:gamer.protocol.RoomItemMsgProtocol)
  SharedDtor();
}

void RoomItemMsgProtocol::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RoomItemMsgProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RoomItemMsgProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RoomItemMsgProtocol_descriptor_;
}

const RoomItemMsgProtocol& RoomItemMsgProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  return *default_instance_;
}

RoomItemMsgProtocol* RoomItemMsgProtocol::default_instance_ = NULL;

RoomItemMsgProtocol* RoomItemMsgProtocol::New() const {
  return new RoomItemMsgProtocol;
}

void RoomItemMsgProtocol::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<RoomItemMsgProtocol*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(room_id_, cur_players_num_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RoomItemMsgProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.protocol.RoomItemMsgProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 room_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &room_id_)));
          set_has_room_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_room_type;
        break;
      }

      // optional uint32 room_type = 2;
      case 2: {
        if (tag == 16) {
         parse_room_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &room_type_)));
          set_has_room_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_sub_room_type;
        break;
      }

      // optional uint32 sub_room_type = 3;
      case 3: {
        if (tag == 24) {
         parse_sub_room_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &sub_room_type_)));
          set_has_sub_room_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_score_type;
        break;
      }

      // optional uint32 score_type = 4;
      case 4: {
        if (tag == 32) {
         parse_score_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_type_)));
          set_has_score_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_cost_score;
        break;
      }

      // optional uint32 cost_score = 5;
      case 5: {
        if (tag == 40) {
         parse_cost_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &cost_score_)));
          set_has_cost_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_min_score;
        break;
      }

      // optional uint32 min_score = 6;
      case 6: {
        if (tag == 48) {
         parse_min_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &min_score_)));
          set_has_min_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_base_score;
        break;
      }

      // optional uint32 base_score = 7;
      case 7: {
        if (tag == 56) {
         parse_base_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &base_score_)));
          set_has_base_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_cur_players_num;
        break;
      }

      // optional uint32 cur_players_num = 8;
      case 8: {
        if (tag == 64) {
         parse_cur_players_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &cur_players_num_)));
          set_has_cur_players_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.protocol.RoomItemMsgProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.protocol.RoomItemMsgProtocol)
  return false;
#undef DO_
}

void RoomItemMsgProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.protocol.RoomItemMsgProtocol)
  // required uint32 room_id = 1;
  if (has_room_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->room_id(), output);
  }

  // optional uint32 room_type = 2;
  if (has_room_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->room_type(), output);
  }

  // optional uint32 sub_room_type = 3;
  if (has_sub_room_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->sub_room_type(), output);
  }

  // optional uint32 score_type = 4;
  if (has_score_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->score_type(), output);
  }

  // optional uint32 cost_score = 5;
  if (has_cost_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->cost_score(), output);
  }

  // optional uint32 min_score = 6;
  if (has_min_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->min_score(), output);
  }

  // optional uint32 base_score = 7;
  if (has_base_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->base_score(), output);
  }

  // optional uint32 cur_players_num = 8;
  if (has_cur_players_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->cur_players_num(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.protocol.RoomItemMsgProtocol)
}

::google::protobuf::uint8* RoomItemMsgProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.protocol.RoomItemMsgProtocol)
  // required uint32 room_id = 1;
  if (has_room_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->room_id(), target);
  }

  // optional uint32 room_type = 2;
  if (has_room_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->room_type(), target);
  }

  // optional uint32 sub_room_type = 3;
  if (has_sub_room_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->sub_room_type(), target);
  }

  // optional uint32 score_type = 4;
  if (has_score_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->score_type(), target);
  }

  // optional uint32 cost_score = 5;
  if (has_cost_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->cost_score(), target);
  }

  // optional uint32 min_score = 6;
  if (has_min_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->min_score(), target);
  }

  // optional uint32 base_score = 7;
  if (has_base_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->base_score(), target);
  }

  // optional uint32 cur_players_num = 8;
  if (has_cur_players_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->cur_players_num(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.protocol.RoomItemMsgProtocol)
  return target;
}

int RoomItemMsgProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 room_id = 1;
    if (has_room_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->room_id());
    }

    // optional uint32 room_type = 2;
    if (has_room_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->room_type());
    }

    // optional uint32 sub_room_type = 3;
    if (has_sub_room_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->sub_room_type());
    }

    // optional uint32 score_type = 4;
    if (has_score_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->score_type());
    }

    // optional uint32 cost_score = 5;
    if (has_cost_score()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->cost_score());
    }

    // optional uint32 min_score = 6;
    if (has_min_score()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->min_score());
    }

    // optional uint32 base_score = 7;
    if (has_base_score()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->base_score());
    }

    // optional uint32 cur_players_num = 8;
    if (has_cur_players_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->cur_players_num());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RoomItemMsgProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RoomItemMsgProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RoomItemMsgProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RoomItemMsgProtocol::MergeFrom(const RoomItemMsgProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_room_id()) {
      set_room_id(from.room_id());
    }
    if (from.has_room_type()) {
      set_room_type(from.room_type());
    }
    if (from.has_sub_room_type()) {
      set_sub_room_type(from.sub_room_type());
    }
    if (from.has_score_type()) {
      set_score_type(from.score_type());
    }
    if (from.has_cost_score()) {
      set_cost_score(from.cost_score());
    }
    if (from.has_min_score()) {
      set_min_score(from.min_score());
    }
    if (from.has_base_score()) {
      set_base_score(from.base_score());
    }
    if (from.has_cur_players_num()) {
      set_cur_players_num(from.cur_players_num());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RoomItemMsgProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RoomItemMsgProtocol::CopyFrom(const RoomItemMsgProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RoomItemMsgProtocol::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void RoomItemMsgProtocol::Swap(RoomItemMsgProtocol* other) {
  if (other != this) {
    std::swap(room_id_, other->room_id_);
    std::swap(room_type_, other->room_type_);
    std::swap(sub_room_type_, other->sub_room_type_);
    std::swap(score_type_, other->score_type_);
    std::swap(cost_score_, other->cost_score_);
    std::swap(min_score_, other->min_score_);
    std::swap(base_score_, other->base_score_);
    std::swap(cur_players_num_, other->cur_players_num_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RoomItemMsgProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RoomItemMsgProtocol_descriptor_;
  metadata.reflection = RoomItemMsgProtocol_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RoomListMsgProtocol::kPlayerIdFieldNumber;
const int RoomListMsgProtocol::kRoomItemsFieldNumber;
#endif  // !_MSC_VER

RoomListMsgProtocol::RoomListMsgProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.protocol.RoomListMsgProtocol)
}

void RoomListMsgProtocol::InitAsDefaultInstance() {
}

RoomListMsgProtocol::RoomListMsgProtocol(const RoomListMsgProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.protocol.RoomListMsgProtocol)
}

void RoomListMsgProtocol::SharedCtor() {
  _cached_size_ = 0;
  player_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RoomListMsgProtocol::~RoomListMsgProtocol() {
  // @@protoc_insertion_point(destructor:gamer.protocol.RoomListMsgProtocol)
  SharedDtor();
}

void RoomListMsgProtocol::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RoomListMsgProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RoomListMsgProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RoomListMsgProtocol_descriptor_;
}

const RoomListMsgProtocol& RoomListMsgProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_room_5flist_5fmsg_5fprotocol_2eproto();
  return *default_instance_;
}

RoomListMsgProtocol* RoomListMsgProtocol::default_instance_ = NULL;

RoomListMsgProtocol* RoomListMsgProtocol::New() const {
  return new RoomListMsgProtocol;
}

void RoomListMsgProtocol::Clear() {
  player_id_ = 0u;
  room_items_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RoomListMsgProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.protocol.RoomListMsgProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 player_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &player_id_)));
          set_has_player_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_room_items;
        break;
      }

      // repeated .gamer.protocol.RoomItemMsgProtocol room_items = 2;
      case 2: {
        if (tag == 18) {
         parse_room_items:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_room_items()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_room_items;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.protocol.RoomListMsgProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.protocol.RoomListMsgProtocol)
  return false;
#undef DO_
}

void RoomListMsgProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.protocol.RoomListMsgProtocol)
  // required uint32 player_id = 1;
  if (has_player_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->player_id(), output);
  }

  // repeated .gamer.protocol.RoomItemMsgProtocol room_items = 2;
  for (int i = 0; i < this->room_items_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->room_items(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.protocol.RoomListMsgProtocol)
}

::google::protobuf::uint8* RoomListMsgProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.protocol.RoomListMsgProtocol)
  // required uint32 player_id = 1;
  if (has_player_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->player_id(), target);
  }

  // repeated .gamer.protocol.RoomItemMsgProtocol room_items = 2;
  for (int i = 0; i < this->room_items_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->room_items(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.protocol.RoomListMsgProtocol)
  return target;
}

int RoomListMsgProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 player_id = 1;
    if (has_player_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->player_id());
    }

  }
  // repeated .gamer.protocol.RoomItemMsgProtocol room_items = 2;
  total_size += 1 * this->room_items_size();
  for (int i = 0; i < this->room_items_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->room_items(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RoomListMsgProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RoomListMsgProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RoomListMsgProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RoomListMsgProtocol::MergeFrom(const RoomListMsgProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  room_items_.MergeFrom(from.room_items_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_player_id()) {
      set_player_id(from.player_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RoomListMsgProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RoomListMsgProtocol::CopyFrom(const RoomListMsgProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RoomListMsgProtocol::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->room_items())) return false;
  return true;
}

void RoomListMsgProtocol::Swap(RoomListMsgProtocol* other) {
  if (other != this) {
    std::swap(player_id_, other->player_id_);
    room_items_.Swap(&other->room_items_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RoomListMsgProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RoomListMsgProtocol_descriptor_;
  metadata.reflection = RoomListMsgProtocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
